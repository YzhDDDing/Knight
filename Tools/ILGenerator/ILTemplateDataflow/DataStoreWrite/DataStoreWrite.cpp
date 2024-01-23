#pragma once
#include "../BasicTemplate.h"


// ��������˿ڵ�����Դ�����ƶϸ�������ж˿ڵ��������ͼ����鳤��



void transTypeInference()
{
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

    string dimensions = actorInfo->getParameterValueByName("Dimensions");
    vector<int> arraySize = parseUtilityArraySize(dimensions);

    if(arraySize.empty())
    {
        expressionStr += actorInfo->getParameterValueByName("DataStoreName") + " = ";
        expressionStr += getCGTActorExeTransSourceOutportVariableNameByName(actorInfo->inports[0]->sourceOutport) + ";";
    }
    else
    {
        int size = 1;
        for(int i = 0; i < arraySize.size(); i++)
            size *= arraySize[i];
        expressionStr += "for(int " + actorInfo->name + "_i" + " = 0; " + actorInfo->name + "_i < " + to_string(size) + "; " + actorInfo->name + "_i++) {\n";

        expressionStr += actorInfo->getParameterValueByName("DataStoreName") + "[" + actorInfo->name + "_i" + "]" + " = ";
        expressionStr += getCGTActorExeTransSourceOutportVariableNameByName(actorInfo->inports[0]->sourceOutport) + "[" + actorInfo->name + "_i" + "]" + ";\n";

        expressionStr += "}";
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

    ILGlobalVariable temp;

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