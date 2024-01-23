#pragma once
#include "../BasicTemplate.h"


// ��������˿ڵ�����Դ�����ƶϸ�������ж˿ڵ��������ͼ����鳤��



void transTypeInference()
{
    string outDataTypeStr = actorInfo->getParameterValueByName("OutDataTypeStr");
    if(outDataTypeStr.empty())
        outDataTypeStr = "f32";
    else if(basicTypeNameMap.find(outDataTypeStr) != basicTypeNameMap.end())
        outDataTypeStr = basicTypeNameMap.at(outDataTypeStr);

    string dimensions = actorInfo->getParameterValueByName("Dimensions");

    actorInfo->outports[0]->type = outDataTypeStr;
    actorInfo->outports[0]->arraySize = parseUtilityArraySize(dimensions);
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

    string expressionStr;

    if(actorInfo->outports[0]->arraySize.empty())
    {
        expressionStr += actorInfo->name + "_" + actorInfo->outports[0]->name + " = ";
        expressionStr += actorInfo->getParameterValueByName("DataStoreName") + ";";
    }/*
    else
    {
        
        int size = 1;
        for(int i = 0; i < actorInfo->outports[0]->arraySize.size(); i++)
            size *= actorInfo->outports[0]->arraySize[i];
        expressionStr += "for(int " + actorInfo->name + "_i" + " = 0; " + actorInfo->name + "_i < " + to_string(size) + "; " + actorInfo->name + "_i++) {\n";

        expressionStr += actorInfo->name + "_" + actorInfo->outports[0]->name + "[" + actorInfo->name + "_i" + "]" + " = ";
        expressionStr += actorInfo->getParameterValueByName("DataStoreName") + "[" + actorInfo->name + "_i" + "]" + ";\n";

        expressionStr += "}";
        
    }*/

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

    ILLocalVariable temp;

    temp.name = actorInfo->name + "_" + actorInfo->outports[0]->name;
    temp.type = actorInfo->outports[0]->type;
    
    if(!actorInfo->outports[0]->arraySize.empty())
    {
        temp.isAddress = 1;
        string valueExp = "&(";
        valueExp += actorInfo->getParameterValueByName("DataStoreName");
        valueExp += "[0]);";
        ILExpressionParser expParser;
        temp.defaultValue = expParser.parseExpression(valueExp);
    }

    ret.push_back(temp);

    return ret;
}

vector<StmtBatchCalculation> transExecBatchCalculation()
{
    vector<StmtBatchCalculation> ret;

    return ret;
}