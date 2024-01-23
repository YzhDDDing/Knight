#pragma once
#include "../BasicTemplate.h"


// 根据输入端口的数据源类型推断该组件所有端口的数据类型及数组长度



void transTypeInference()
{
    // 输入 actorInfo.inports.source
    // 输出 actorInfo.inports.type / arraySize
    // 输出 actorInfo.outports.type / arraySize
    transTypeInferencePassInportFromSrc();

    string para = actorInfo->getParameterValueByName("Operator");
    para = (para == "") ? "exp" : para;
    if(para == "square") {
        actorInfo->outports[0]->type = actorInfo->inports[0]->type;
    } else if(para == "exp" || para == "sqrt" || para == "log" || para == "log10") {
        actorInfo->outports[0]->type = actorInfo->inports[0]->type == "f64" ? "f64" : "f32";
    } else {
        transTypeInferenceOutportSameAsInport();
    }
    
    string simulinkType = getSimulinkOutDataType();
    if(simulinkType != "#Default")
        actorInfo->outports[0]->type = simulinkType;

    actorInfo->outports[0]->arraySize = actorInfo->inports[0]->arraySize;
}


// 仅组装表达式，剩余的在组件的BasicTemplate中构造

string transInitExpression()
{
    return "";
}

// 仅组装表达式，剩余的在组件的BasicTemplate中构造

string transExecExpression()
{
    if(actorInfo->inports.empty())
        return "";

    string expressionStr;
	expressionStr += actorInfo->name + "_" + actorInfo->outports[0]->name + " = ";

	string para = actorInfo->getParameterValueByName("Operator");
    para = (para == "") ? "exp" : para;

    if(para == "square") {
        expressionStr += getCGTActorExeTransSourceOutportVariableNameByName(actorInfo->inports[0]->sourceOutport);
        expressionStr += "*";
        expressionStr += getCGTActorExeTransSourceOutportVariableNameByName(actorInfo->inports[0]->sourceOutport);
    } else if(para == "exp") {
        expressionStr += "exp(";
        expressionStr += getCGTActorExeTransSourceOutportVariableNameByName(actorInfo->inports[0]->sourceOutport);
        expressionStr += ")";
    } else if(para == "sqrt") {
        expressionStr += "sqrt(";
        expressionStr += getCGTActorExeTransSourceOutportVariableNameByName(actorInfo->inports[0]->sourceOutport);
        expressionStr += ")";
    } else if(para == "log") {
        expressionStr += "log(";
        expressionStr += getCGTActorExeTransSourceOutportVariableNameByName(actorInfo->inports[0]->sourceOutport);
        expressionStr += ")";
    } else if(para == "log10") {
        expressionStr += "log10(";
        expressionStr += getCGTActorExeTransSourceOutportVariableNameByName(actorInfo->inports[0]->sourceOutport);
        expressionStr += ")";
    } else  if(para == "mod") {
        expressionStr += getCGTActorExeTransSourceOutportVariableNameByName(actorInfo->inports[0]->sourceOutport);
        expressionStr += "%";
        expressionStr += getCGTActorExeTransSourceOutportVariableNameByName(actorInfo->inports[1]->sourceOutport);
    } 
    expressionStr += ";";

    return expressionStr;
}

// 无需添加下面各个IL返回值的ref

vector<ILHeadFile> transHeadFile()
{
    vector<ILHeadFile> ret;

    string para = actorInfo->getParameterValueByName("Operator");
    para = (para == "") ? "exp" : para;

    if(para == "exp" || para == "sqrt" || para == "log" || para == "log10") {
       ILHeadFile temp;
       temp.name = "math";
       ret.push_back(temp);
    }
    //ILHeadFile temp;
    //temp.name = "math";
    //ret.push_back(temp);
    return ret;
}

vector<ILMacro> transMacro()
{
    vector<ILMacro> ret;
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

map<string, StmtBatchCalculation::OperationType> operatorMapOneInput = {
    pair<string, StmtBatchCalculation::OperationType>("exp", StmtBatchCalculation::TypeExp),
    pair<string, StmtBatchCalculation::OperationType>("square", StmtBatchCalculation::TypeSquare),
    pair<string, StmtBatchCalculation::OperationType>("sqrt", StmtBatchCalculation::TypeSqrt),
    pair<string, StmtBatchCalculation::OperationType>("log", StmtBatchCalculation::TypeLog),
    pair<string, StmtBatchCalculation::OperationType>("log10", StmtBatchCalculation::TypeLog10),
};

map<string, StmtBatchCalculation::OperationType> operatorMapTwoInput = {
    pair<string, StmtBatchCalculation::OperationType>("mod", StmtBatchCalculation::TypeMod),
};

vector<StmtBatchCalculation> transExecBatchCalculation()
{
    string para = actorInfo->getParameterValueByName("Operator");
    para = (para == "") ? "exp" : para;

    vector<StmtBatchCalculation> ret;
    if(actorInfo->inports.size() < 1 || 
        actorInfo->inports[0]->arraySize.empty())
        return ret;
    CGTActorExeTransOutport* outport = actorInfo->outports[0];
    StmtBatchCalculation stmt;

    stmt.dataType = outport->type;

    
    CGTActorExeTransInport* inport1 = actorInfo->inports[0];
    StmtBatchCalculation::StmtBatchCalculationInput stmtInput1;
    stmtInput1.name = getCGTActorExeTransSourceOutportVariableNameByName(inport1->sourceOutport);
    stmtInput1.type = inport1->type;
    stmtInput1.arraySize = inport1->arraySize;
    stmt.inputs.push_back(stmtInput1);

    if(operatorMapOneInput.find(para) != operatorMapOneInput.end())
    {
        stmt.operationType = operatorMapOneInput.at(para);
    } else if(operatorMapTwoInput.find(para) != operatorMapTwoInput.end()) {
        stmt.operationType = operatorMapTwoInput.at(para);

        CGTActorExeTransInport* inport2 = actorInfo->inports[1];
        StmtBatchCalculation::StmtBatchCalculationInput stmtInput2;
        stmtInput2.name = getCGTActorExeTransSourceOutportVariableNameByName(inport2->sourceOutport);
        stmtInput2.type = inport2->type;
        stmtInput2.arraySize = inport2->arraySize;
        stmt.inputs.push_back(stmtInput2);
    }
    


    //CGTActorExeTransInport* inport2 = actorInfo->inports[1];
    //StmtBatchCalculation::StmtBatchCalculationInput stmtInput2;
    //stmtInput2.name = getCGTActorExeTransSourceOutportVariableNameByName(inport2->sourceOutport);
    //stmtInput2.type = inport2->type;
    //stmtInput2.arraySize = inport2->arraySize;
    //stmt.inputs.push_back(stmtInput2);


    StmtBatchCalculation::StmtBatchCalculationOutput stmtOutput;
    stmtOutput.name = actorInfo->name + "_" + outport->name;
    stmtOutput.type = outport->type;
    stmtOutput.arraySize = outport->arraySize;
    stmt.outputs.push_back(stmtOutput);

    ret.push_back(stmt);

    return ret;
}