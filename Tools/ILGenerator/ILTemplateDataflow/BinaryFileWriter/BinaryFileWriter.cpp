#pragma once
#include "../BasicTemplate.h"


// ��������˿ڵ�����Դ�����ƶϸ�������ж˿ڵ��������ͼ����鳤��



void transTypeInference()
{
    transTypeInferencePassInportFromSrc();
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

    CGTActorExeTransInport* inport = actorInfo->inports[0];
    string inportType = inport->type; 
    if(basicTypeNameMap.find(inportType) != basicTypeNameMap.end())
        inportType = basicTypeNameMap.at(inport->type);

    int arraySize = 1;
    if(!inport->arraySize.empty())
    {
        for(int i = 0; i < inport->arraySize.size(); i++)
            arraySize *= inport->arraySize[i];
    }

    expressionStr += "binaryFileAppend_" + inportType + "(";
    expressionStr += "\"" + actorInfo->getParameterValueByName("Filename") + "\", ";
    if(inport->arraySize.empty())
        expressionStr += "&";
    expressionStr += getCGTActorExeTransSourceOutportVariableNameByName(actorInfo->inports[0]->sourceOutport) + ", ";
    expressionStr += to_string(arraySize) + ");";

    return expressionStr;
}

// ��������������IL����ֵ��ref

vector<ILHeadFile> transHeadFile()
{
    vector<ILHeadFile> ret;

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

    ILUtilityFunction temp;
    string inportType = actorInfo->inports[0]->type; 
    if(basicTypeNameMap.find(inportType) != basicTypeNameMap.end())
        inportType = basicTypeNameMap.at(actorInfo->inports[0]->type);
    temp.name = "binaryFileAppend_" + inportType;
    ret.push_back(temp);

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

    return ret;
}

vector<StmtBatchCalculation> transExecBatchCalculation()
{
    vector<StmtBatchCalculation> ret;

    return ret;
}