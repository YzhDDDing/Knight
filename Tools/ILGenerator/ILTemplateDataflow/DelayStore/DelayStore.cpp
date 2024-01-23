#pragma once
#include "../BasicTemplate.h"


// 根据输入端口的数据源类型推断该组件所有端口的数据类型及数组长度



void transTypeInference()
{
    // 输入 actorInfo.inports.source
    // 输出 actorInfo.inports.type / arraySize
    // 输出 actorInfo.outports.type / arraySize
    if(!actorInfo->inports.empty()) {
        CGTActorExeTransInport* inport = actorInfo->inports[0];
        CGTActorExeTransSourceOutport* src = getCGTActorExeTransSourceOutportByName(inport->sourceOutport);
        if(inport->type == "#Default") {
            inport->type = src->type;
        }
        if(inport->arraySize.empty()) {
            inport->arraySize = src->arraySize;
        }
        string inputPortWidthStr = actorInfo->getParameterValueByName("InputPortWidth");
        if(!inputPortWidthStr.empty()) {
            inport->arraySize.clear();
            inport->arraySize.push_back(stringToInt(inputPortWidthStr));
        }
    }
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
	expressionStr += actorInfo->getParameterValueByName("StateVariableName") + " = ";

    expressionStr += getCGTActorExeTransSourceOutportVariableNameByName(actorInfo->inports[0]->sourceOutport) + ";";
    
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
    if(actorInfo->inports.empty())
        return ret;

    ILGlobalVariable temp;
    temp.name = actorInfo->getParameterValueByName("StateVariableName");
    temp.type = actorInfo->inports[0]->type;
    temp.arraySize = actorInfo->inports[0]->arraySize;

    string initValue = actorInfo->getParameterValueByName("InitialCondition");
    if(!initValue.empty())
    {
        temp.defaultValue = ILExpressionParser::parseExpression(initValue);
    }

    ret.push_back(temp);

    return ret;
}

vector<ILLocalVariable> transLocalVariable()
{
    vector<ILLocalVariable> ret;
    return ret;
}

vector<StmtBatchCalculation> transExecBatchCalculation()
{
    vector<StmtBatchCalculation> ret;
    if(actorInfo->inports.empty() || actorInfo->inports[0]->arraySize.empty())
        return ret;
    //CGTActorExeTransOutport* outport = actorInfo->outports[0];
    StmtBatchCalculation stmt;
    stmt.operationType = StmtBatchCalculation::TypeAssign;
    
    CGTActorExeTransInport* inport = actorInfo->inports[0];
    stmt.dataType = inport->type;
    StmtBatchCalculation::StmtBatchCalculationInput stmtInput;
    stmtInput.name = getCGTActorExeTransSourceOutportVariableNameByName(inport->sourceOutport);
    stmtInput.type = inport->type;
    stmtInput.arraySize = inport->arraySize;
    stmt.inputs.push_back(stmtInput);

    StmtBatchCalculation::StmtBatchCalculationOutput stmtOutput;
    stmtOutput.name = actorInfo->getParameterValueByName("StateVariableName");
    stmtOutput.type = inport->type;
    stmtOutput.arraySize = inport->arraySize;
    stmt.outputs.push_back(stmtOutput);

    ret.push_back(stmt);

    return ret;
}