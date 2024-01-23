#pragma once
#include "../BasicTemplate.h"


// ��������˿ڵ�����Դ�����ƶϸ�������ж˿ڵ��������ͼ����鳤��



void transTypeInference()
{
    // ���� actorInfo.inports.source
    // ��� actorInfo.inports.type / arraySize
    // ��� actorInfo.outports.type / arraySize
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


// ����װ���ʽ��ʣ����������BasicTemplate�й���

string transInitExpression()
{
    return "";
}

// ����װ���ʽ��ʣ����������BasicTemplate�й���

string transExecExpression()
{
    if(actorInfo->inports.empty())
        return "";

    string expressionStr;
	expressionStr += actorInfo->getParameterValueByName("StateVariableName") + " = ";

    expressionStr += getCGTActorExeTransSourceOutportVariableNameByName(actorInfo->inports[0]->sourceOutport) + ";";
    
    return expressionStr;
}

// ��������������IL����ֵ��ref

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