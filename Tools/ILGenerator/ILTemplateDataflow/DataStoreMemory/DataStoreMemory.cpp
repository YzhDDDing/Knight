#pragma once
#include "../BasicTemplate.h"


// ��������˿ڵ�����Դ�����ƶϸ�������ж˿ڵ��������ͼ����鳤��



void transTypeInference()
{
}


// ����װ���ʽ��ʣ����������BasicTemplate�й���

string transInitExpression()
{
    string expressionStr;
    string dimensions = actorInfo->getParameterValueByName("Dimensions");
    if(dimensions.empty())
    {
        string initialValueStr = actorInfo->getParameterValueByName("InitialValue");
        if(initialValueStr.empty())
            initialValueStr = "0";

        expressionStr = actorInfo->getParameterValueByName("DataStoreName") + " = " + initialValueStr + ";";
    }
    else
        expressionStr = "memset(" + actorInfo->getParameterValueByName("DataStoreName") + ", 0, sizeof(" + actorInfo->getParameterValueByName("DataStoreName") + "));";


    return expressionStr;
}

// ����װ���ʽ��ʣ����������BasicTemplate�й���

string transExecExpression()
{
    return "";
}

// ��������������IL����ֵ��ref

vector<ILHeadFile> transHeadFile()
{
    vector<ILHeadFile> ret;

    string expressionStr;
    string dimensions = actorInfo->getParameterValueByName("Dimensions");
    if(!dimensions.empty())
    {
        ILHeadFile temp;
        temp.name = "string";
        ret.push_back(temp);
    }
    
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

    string outDataTypeStr = actorInfo->getParameterValueByName("OutDataTypeStr");
    if(outDataTypeStr.empty())
        outDataTypeStr = "f32";
    else if(basicTypeNameMap.find(outDataTypeStr) != basicTypeNameMap.end())
        outDataTypeStr = basicTypeNameMap.at(outDataTypeStr);

    string dimensions = actorInfo->getParameterValueByName("Dimensions");
    
    temp.name = actorInfo->getParameterValueByName("DataStoreName");
    temp.type = outDataTypeStr;
    temp.arraySize = parseUtilityArraySize(dimensions);

    //ILExpressionParser expressionParser;
    //temp.defaultValue = expressionParser.parseExpression("0");

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

    return ret;
}