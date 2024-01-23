#pragma once
#include "../BasicTemplate.h"

#include <map>
// 根据输入端口的数据源类型推断该组件所有端口的数据类型及数组长度



void transTypeInference()
{
    // 输入 actorInfo.inports.source
    // 输出 actorInfo.inports.type / arraySize
    // 输出 actorInfo.outports.type / arraySize

    transTypeInferencePassInportFromSrc();

    if(actorInfo->inports.empty())
        return;
    if(actorInfo->outports.empty())
        return;

    CGTActorExeTransOutport* outport = actorInfo->outports[0];
    outport->type = "bool";
    for(int i = 0; i < actorInfo->inports.size(); i++)
    {
        if(outport->arraySize.empty() && !actorInfo->inports[i]->arraySize.empty())
        {
            outport->arraySize = actorInfo->inports[i]->arraySize;
        }
    }

    
}


// 仅组装表达式，剩余的在组件的BasicTemplate中构造

string transInitExpression()
{
    return "";
}

// 仅组装表达式，剩余的在组件的BasicTemplate中构造

namespace{
    map<string, string> operatorCodeMap = {
           pair<string, string>("AND", "&&"),
           pair<string, string>("OR", "||"),
           pair<string, string>("XOR", "^"),
           pair<string, string>("NAND", "&&"),
           pair<string, string>("NOR", "||"),
           pair<string, string>("NXOR", "^"),
       };
}


string transExecExpression()
{
    if(actorInfo->outports.empty() || actorInfo->inports.empty())
        return "";

    string expressionStr;
	expressionStr += actorInfo->name + "_" + actorInfo->outports[0]->name + " = ";
    string para = actorInfo->getParameterValueByName("Operator");
    if(para.empty())
        para = "AND";
    if(para == "NOT"){
        expressionStr += "!" + getCGTActorExeTransSourceOutportVariableNameByName(actorInfo->inports[0]->sourceOutport);
    } else if(operatorCodeMap.find(para) != operatorCodeMap.end()) {
        string op = operatorCodeMap.at(para);
        if(stringStartsWith(para, "N"))
            expressionStr += "!";
        expressionStr += "(";
        for(int i = 0; i < actorInfo->inports.size(); i++)
        {
            if(i != 0)
                expressionStr += op;
            expressionStr += getCGTActorExeTransSourceOutportVariableNameByName(actorInfo->inports[i]->sourceOutport);
        }
        expressionStr += ")";
    }
    
    expressionStr += ";";

    return expressionStr;
}

// 无需添加下面各个IL返回值的ref

vector<ILHeadFile> transHeadFile()
{
    vector<ILHeadFile> ret;
    //ILHeadFile temp;
    //temp.name = "math";
    //ret.push_back(temp);
    return ret;
}

vector<ILMacro> transMacro()
{
    vector<ILMacro> ret;

    ILMacro boolDefine;
    boolDefine.name = "bool";
    boolDefine.value = "unsigned char";

    ret.push_back(boolDefine);
    return ret;
}

vector<ILTypeDefine> transTypeDefine()
{
    vector<ILTypeDefine> ret;
    return ret;
}

vector<ILEnumDefine> transEnumDefine()
{
    vector<ILEnumDefine> ret;
    return ret;
}

vector<ILStructDefine> transStructDefine()
{
    vector<ILStructDefine> ret;
    return ret;
}

vector<ILUtilityFunction> transUtilityFunction()
{
    vector<ILUtilityFunction> ret;
    return ret;
}

vector<ILGlobalVariable> transGlobalVariable()
{
    vector<ILGlobalVariable> ret;
    return ret;
}

vector<ILLocalVariable> transLocalVariable()
{
    vector<ILLocalVariable> ret;
    if(actorInfo->outports.empty() || actorInfo->inports.empty())
        return ret;

    ILLocalVariable temp;
    temp.name = actorInfo->name + "_" + actorInfo->outports[0]->name;
    temp.type = actorInfo->outports[0]->type;
    temp.arraySize = actorInfo->outports[0]->arraySize;

    ret.push_back(temp);
    
    return ret;
}

map<string, StmtBatchCalculation::OperationType> operatorMap = {
    pair<string, StmtBatchCalculation::OperationType>("NOT", StmtBatchCalculation::TypeLogicNot),
    pair<string, StmtBatchCalculation::OperationType>("AND", StmtBatchCalculation::TypeLogicAnd),
    pair<string, StmtBatchCalculation::OperationType>("OR", StmtBatchCalculation::TypeLogicOr),
    pair<string, StmtBatchCalculation::OperationType>("XOR", StmtBatchCalculation::TypeLogicXor),
    pair<string, StmtBatchCalculation::OperationType>("NAND", StmtBatchCalculation::TypeLogicNAnd),
    pair<string, StmtBatchCalculation::OperationType>("NOR", StmtBatchCalculation::TypeLogicNOr),
    pair<string, StmtBatchCalculation::OperationType>("NXOR", StmtBatchCalculation::TypeLogicNXor),
};

vector<StmtBatchCalculation> transExecBatchCalculation()
{
    vector<StmtBatchCalculation> ret;

    if(actorInfo->outports.empty() || actorInfo->inports.empty() || actorInfo->outports[0]->arraySize.empty())
        return ret;

    CGTActorExeTransOutport* outport = actorInfo->outports[0];
    StmtBatchCalculation stmt;
    string para = actorInfo->getParameterValueByName("Operator");
    stmt.operationType = operatorMap.at(para);
    stmt.dataType = outport->type;

    
    CGTActorExeTransInport* inport1 = actorInfo->inports[0];
    StmtBatchCalculation::StmtBatchCalculationInput stmtInput1;
    stmtInput1.name = getCGTActorExeTransSourceOutportVariableNameByName(inport1->sourceOutport);
    stmtInput1.type = inport1->type;
    stmtInput1.arraySize = inport1->arraySize;
    stmt.inputs.push_back(stmtInput1);

    if(para != "NOT")
    {
        CGTActorExeTransInport* inport2 = actorInfo->inports[1];
        StmtBatchCalculation::StmtBatchCalculationInput stmtInput2;
        stmtInput2.name = getCGTActorExeTransSourceOutportVariableNameByName(inport2->sourceOutport);
        stmtInput2.type = inport2->type;
        stmtInput2.arraySize = inport2->arraySize;
        stmt.inputs.push_back(stmtInput2);
    }

    StmtBatchCalculation::StmtBatchCalculationOutput stmtOutput;
    stmtOutput.name = actorInfo->name + "_" + outport->name;
    stmtOutput.type = outport->type;
    stmtOutput.arraySize = outport->arraySize;
    stmt.outputs.push_back(stmtOutput);

    ret.push_back(stmt);


    return ret;
}
