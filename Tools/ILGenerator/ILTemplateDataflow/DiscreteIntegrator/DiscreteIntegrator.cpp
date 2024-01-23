#pragma once
#include "../BasicTemplate.h"

// ��������˿ڵ�����Դ�����ƶϸ�������ж˿ڵ��������ͼ����鳤��

void transTypeInference()
{
    // ���� actorInfo.inports.source
    // ��� actorInfo.inports.type / arraySize
    // ��� actorInfo.outports.type / arraySize
    transTypeInferenceOutportSameAsInport();
}


// ����װ���ʽ��ʣ����������BasicTemplate�й���

string transInitExpression()
{
    return "";
}

// ����װ���ʽ��ʣ����������BasicTemplate�й���

string transExecExpression()
{
    if(actorInfo->outports.empty())
        return "";

    string assignmentStr = actorInfo->name + "_" + actorInfo->outports[0]->name + " = ";
    assignmentStr += actorInfo->name + "_state;";

    string updateStr = actorInfo->name + "_state = ";
    updateStr += actorInfo->name + "_state + ";

    string gain = actorInfo->getParameterValueByName("Gainval");
    if(gain.empty()) {
        updateStr += getCGTActorExeTransSourceOutportVariableNameByName(actorInfo->inports[0]->sourceOutport);
    } else {
        updateStr += getCGTActorExeTransSourceOutportVariableNameByName(actorInfo->inports[0]->sourceOutport) + " * " + gain;
    }
    updateStr += ";";

    
    string expressionStr;
    string integratorMethod = actorInfo->getParameterValueByName("IntegratorMethod");
    if(integratorMethod == "Accumulation: Forward Euler")
    {
        expressionStr = assignmentStr + "\n" + updateStr;
    }
    else if(integratorMethod == "Accumulation: Backward Euler")
    {
        expressionStr = updateStr + "\n" + assignmentStr;
    }

    
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

    if(actorInfo->outports.empty() || actorInfo->inports.empty())
        return ret;

    ILGlobalVariable temp;
    temp.name = actorInfo->name + "_state";
    temp.type = actorInfo->outports[0]->type;
    temp.arraySize = actorInfo->outports[0]->arraySize;

    string initValue = actorInfo->getParameterValueByName("InitialCondition");
    if(initValue.empty()) {
        initValue = "0";
    }
    temp.defaultValue = ILExpressionParser::parseExpression(initValue);

    ret.push_back(temp);

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

vector<StmtBatchCalculation> transExecBatchCalculation()
{
    vector<StmtBatchCalculation> ret;
    return ret;
}
