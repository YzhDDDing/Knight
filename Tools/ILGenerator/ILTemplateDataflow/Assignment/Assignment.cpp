#pragma once
#include "../BasicTemplate.h"

// 根据输入端口的数据源类型推断该组件所有端口的数据类型及数组长度

void transTypeInference() {
    // 输入 actorInfo.inports.source
    // 输出 actorInfo.inports.type / arraySize
    // 输出 actorInfo.outports.type / arraySize

    transTypeInferencePassInportFromSrc();

    CGTActorExeTransInport *inport = actorInfo->inports[0];
    CGTActorExeTransOutport *outport = actorInfo->outports[0];
    // 默认Y0端口必须连接
    if (outport->type == "#Default") {
        outport->type = inport->type;
        outport->arraySize = inport->arraySize;
    }

    // std::vector<std::string> indexOptions =
    // stringSplit(actorInfo->getParameterValueByName("IndexOptions"),","); int
    // dimensions =
    // stringToInt(actorInfo->getParameterValueByName("NumberOfDimensions"));
}

// 仅组装表达式，剩余的在组件的BasicTemplate中构造

string transInitExpression() { return ""; }

// 仅组装表达式，剩余的在组件的BasicTemplate中构造

int transInAssignAllMode(CGTActorExeTransOutport* outport,
    CGTActorExeTransSourceOutport* assignPort) {
    StmtBatchCalculation* stmt = new StmtBatchCalculation;
    string assignPortName = getCGTActorExeTransSourceOutportVariableNameByPort(assignPort);

    stmt->operationType = StmtBatchCalculation::TypeAssign;
    stmt->dataType = outport->type;

    StmtBatchCalculation::StmtBatchCalculationInput stmtInput;
    stmtInput.name = assignPortName;
    stmtInput.type = assignPort->type;
    stmtInput.arraySize = assignPort->arraySize;
    stmt->inputs.push_back(stmtInput);

    StmtBatchCalculation::StmtBatchCalculationOutput stmtOutput;
    stmtOutput.name = actorInfo->name + "_" + outport->name;
    stmtOutput.type = outport->type;
    stmtOutput.arraySize = outport->arraySize;
    stmt->outputs.push_back(stmtOutput);

    calculateExec.statements.childStatements.push_back(stmt);
    return 1;
}

int transInStartingIndexMode(CGTActorExeTransOutport* outport,
    CGTActorExeTransSourceOutport* assignPort,
    vector<string> indexOptions,
    vector<string> indexStrs, int index) {
    StmtLocalVariable* offsetVariable =
        new StmtLocalVariable(&(calculateExec.statements));
    string offsetStr = actorInfo->name + "_" + outport->name + "_offset";
    offsetVariable->name = offsetStr;
    offsetVariable->dataType = outport->type;
    offsetVariable->isAddress = 1;
    string assignPortName = getCGTActorExeTransSourceOutportVariableNameByPort(assignPort);

    // 设置变量的偏移
    Expression* defaultValueExp = nullptr;
    Expression* tempExp = nullptr;
    string defaultStr;
    if (indexOptions[0] == "Starting index (dialog)") {
        defaultStr =
            actorInfo->name + "_" + outport->name + " + (int)" + to_string(stringToInt(indexStrs[0]) - index);
    }
    else {
        defaultStr = actorInfo->name + "_" + outport->name + " + (int)" + getCGTActorExeTransSourceOutportVariableNameByName(actorInfo->inports[2]->sourceOutport);
        defaultStr += index == 0 ? "" : " - " + to_string(index);
    }
    defaultStr = "v=" + defaultStr;
    ILExpressionParser expressionParser;
    int res = expressionParser.parseExpression(defaultStr, &tempExp);
    if (res < 0)
        printf("Error in parsing expression.\n");
    defaultValueExp = tempExp->childExpressions[1]->clone();
    tempExp->release();
    delete tempExp;
    offsetVariable->innerExpressions.push_back(defaultValueExp);
    offsetVariable->defaultValue = defaultValueExp;

    StmtBatchCalculation* stmt = new StmtBatchCalculation;
    stmt->operationType = StmtBatchCalculation::TypeAssign;
    stmt->dataType = outport->type;

    StmtBatchCalculation::StmtBatchCalculationInput stmtInput;
    stmtInput.name = assignPortName;
    stmtInput.type = assignPort->type;
    stmtInput.arraySize = assignPort->arraySize;
    stmt->inputs.push_back(stmtInput);

    StmtBatchCalculation::StmtBatchCalculationOutput stmtOutput;
    stmtOutput.name = offsetStr;
    stmtOutput.type = outport->type;
    stmtOutput.arraySize = assignPort->arraySize;
    // stmtOutput.isAddress = 1;
    stmt->outputs.push_back(stmtOutput);

    calculateExec.statements.childStatements.push_back(offsetVariable);
    calculateExec.statements.childStatements.push_back(stmt);
    return 1;
}

int transInIndexVectorMode(CGTActorExeTransOutport* outport,
    CGTActorExeTransSourceOutport* assignPort,
    vector<string> indexOptions,
    vector<string> indexStrs, int index) {
    string ret = "";
    string assignPortName = getCGTActorExeTransSourceOutportVariableNameByPort(assignPort);
    string outportName = actorInfo->name + "_" + outport->name;
    if (indexOptions[0] == "Index vector (dialog)") {
        for (auto& indexStr : indexStrs) {
            if (stringStartsWith(indexStr, "["))
            {
                indexStr = indexStr.substr(1, indexStr.length() - 2);
                vector<string> insideIndexs = stringSplit(indexStr, ",");
                for (auto& insideIndex : insideIndexs)
                {
                    ret += actorInfo->name + "_" + outport->name + "[" + to_string(stringToInt(insideIndex) - index) +
                        "]" + " = " + assignPortName + ";\n";
                }
            }
            else
            ret += actorInfo->name + "_" + outport->name + "[" + to_string(stringToInt(indexStr) - index) +
                "]" + " = " + assignPortName + ";\n";
        }
    }
    else {
        CGTActorExeTransSourceOutport* indexPort =
            getCGTActorExeTransSourceOutportByName(
                actorInfo->inports[2]->sourceOutport);
        string indexPortName = getCGTActorExeTransSourceOutportVariableNameByPort(indexPort);
        if (indexPort->arraySize.empty()) {
            ret += index == 0 ? actorInfo->name + "_" + outport->name + "[" + indexPortName +
                "] =" + assignPortName + ";\n"
                : actorInfo->name + "_" + outport->name + "[" + indexPortName + " - 1" +
                "] =" + assignPortName + ";\n";
        }
        else {
            if (indexPort->arraySize[0] > 4) {
                ret += "for (int i = 0; i < " + to_string(indexPort->arraySize[0]) +
                    "; i++)\n";
                ret += "{\n";
                ret += index == 0
                    ? actorInfo->name + "_" + outport->name + "[" + indexPortName +
                    "[i]] = " + assignPortName + ";\n"
                    : actorInfo->name + "_" + outport->name + "[" + indexPortName +
                    "[i] - 1] = " + assignPortName + ";\n";
                ret += "}\n";
            }
            else {
                if (index == 0) {
                    for (int i = 0; i < indexPort->arraySize[0]; i++) {
                        ret += actorInfo->name + "_" + outport->name + "[" + indexPortName + "[" + to_string(i) +
                            "]] =" + assignPortName + ";\n";
                    }
                }
                else {
                    for (int i = 0; i < indexPort->arraySize[0]; i++) {
                        ret += actorInfo->name + "_" + outport->name + "[" + indexPortName + "[" + to_string(i) +
                            " ] - 1] =" + assignPortName + ";\n";
                    }
                }
            }
        }
    }
    ILCCodeParser codeParser;
    int res = codeParser.parseCCode(ret, &calculateExec.statements);
    if (res < 0)
        printf("Error in parsing C code\n");
    return 1;
}

int transAssignment() {
    CGTActorExeTransOutport* outport = actorInfo->outports[0];

    // 默认Y0端口必须连接
    vector<string> indexOptions =
        stringSplit(actorInfo->getParameterValueByName("IndexOptions"), ",");
    string indexMode = actorInfo->getParameterValueByName("IndexMode");
    vector<string> indexStrs =
        getIndexStrs(actorInfo->getParameterValueByName("Indices"));

    int index;
    if (indexMode == "Zero-based") {
        index = 0;
    }
    else {
        // One-based
        index = 1;
    }
    CGTActorExeTransSourceOutport* initialPort =
        getCGTActorExeTransSourceOutportByName(
            actorInfo->inports[0]->sourceOutport);
    // 生成初始化端口Statement
    if (initialPort) {

        StmtIf* initIf = new StmtIf();
        string ifCondition = actorInfo->name + "_init == 0";
        initIf->condition = ILExpressionParser::parseExpression(ifCondition);
        calculateExec.statements.addChildStatement(initIf);

        StmtExpression* initExp = new StmtExpression();
        string exp = actorInfo->name + "_init = 1";
        initExp->expression = ILExpressionParser::parseExpression(exp);
        initIf->addChildStatement(initExp);

        StmtBatchCalculation* stmt = new StmtBatchCalculation;
        stmt->operationType = StmtBatchCalculation::TypeAssign;
        stmt->dataType = outport->type;

        StmtBatchCalculation::StmtBatchCalculationInput stmtInput;
        if (initialPort->actorName.empty())
            stmtInput.name = initialPort->name;
        else
            stmtInput.name = initialPort->actorName + "_" + initialPort->name;
        stmtInput.type = initialPort->type;
        stmtInput.arraySize = initialPort->arraySize;
        stmt->inputs.push_back(stmtInput);

        StmtBatchCalculation::StmtBatchCalculationOutput stmtOutput;
        stmtOutput.name = actorInfo->name + "_" + outport->name;
        stmtOutput.type = outport->type;
        stmtOutput.arraySize = outport->arraySize;
        stmt->outputs.push_back(stmtOutput);

        initIf->addChildStatement(stmt);
    }
    CGTActorExeTransSourceOutport* assignPort =
        getCGTActorExeTransSourceOutportByName(
            actorInfo->inports[1]->sourceOutport);
    // 如果没有AssignPort，则不执行剩余操作
    if (assignPort) {
        if (indexOptions[0] == "Assign all") {
            transInAssignAllMode(outport, assignPort);
        }
        else if (indexOptions[0] == "Starting index (dialog)" ||
            indexOptions[0] == "Starting index (port)") {
            transInStartingIndexMode(outport, assignPort, indexOptions, indexStrs,
                index);
        }
        else if (indexOptions[0] == "Index vector (dialog)" ||
            indexOptions[0] == "Index vector (port)") {
            transInIndexVectorMode(outport, assignPort, indexOptions, indexStrs,
                index);
        }
    }
    return 1;
}

string transExecExpression() {
  string ret;
  transAssignment();
  return ret;
}

// 无需添加下面各个IL返回值的ref

vector<ILHeadFile> transHeadFile() {
    vector<ILHeadFile> ret;
    // ILHeadFile temp;
    // temp.name = "math";
    // ret.push_back(temp);
    return ret;
}

vector<ILMacro> transMacro() {
    vector<ILMacro> ret;
    return ret;
}

vector<ILTypeDefine> transTypeDefine() {
    vector<ILTypeDefine> ret;
    return ret;
}

vector<ILEnumDefine> transEnumDefine() {
    vector<ILEnumDefine> ret;
    return ret;
}

vector<ILStructDefine> transStructDefine() {
    vector<ILStructDefine> ret;
    return ret;
}

vector<ILUtilityFunction> transUtilityFunction() {
    vector<ILUtilityFunction> ret;
    return ret;
}

vector<ILGlobalVariable> transGlobalVariable() {
    vector<ILGlobalVariable> ret;

    return ret;
}

vector<ILLocalVariable> transLocalVariable() {
    vector<ILLocalVariable> ret;
    if (actorInfo->outports.empty() || actorInfo->inports.empty())
        return ret;

    ILLocalVariable temp;
    temp.name = actorInfo->name + "_" + actorInfo->outports[0]->name;
    temp.type = actorInfo->outports[0]->type;
    temp.arraySize = actorInfo->outports[0]->arraySize;

    ret.push_back(temp);
    
    ILLocalVariable temp2;
    temp2.name = actorInfo->name + "_init";
    temp2.type = "u8";
    
    string defaultValue = "0";
    ILExpressionParser expParser;
    temp2.defaultValue = expParser.parseExpression(defaultValue);

    ret.push_back(temp2);

    return ret;
}

vector<StmtBatchCalculation> transExecBatchCalculation() {
    vector<StmtBatchCalculation> ret;
    return ret;
}

