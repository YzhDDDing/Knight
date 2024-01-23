#pragma once
#include "../BasicTemplate.h"


// ��������˿ڵ�����Դ�����ƶϸ�������ж˿ڵ��������ͼ����鳤��



void transTypeInference()
{
    // ���� ActorInfo.inports.source
    // ��� ActorInfo.inports.type / arraySize
    // ��� ActorInfo.outports.type / arraySize
    string type;
    if(!actorInfo->outports.empty())
        type = getSimulinkOutDataType();
    if(type == "#Default")
        type = "f32";
    actorInfo->outports[0]->type = type;

    string valueStr = actorInfo->getParameterValueByName("Value");
    if(stringStartsWith(valueStr, "["))
    {
        valueStr = valueStr.substr(1, valueStr.length() - 2);
        vector<string> valueList = stringSplit(valueStr, ",");
        actorInfo->outports[0]->arraySize.push_back(valueList.size());
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
    if(actorInfo->outports.empty())
        return "";

    string expressionStr;
    string varNameStr;
	varNameStr += actorInfo->name + "_" + actorInfo->outports[0]->name;

    string valueStr = actorInfo->getParameterValueByName("Value");
    if(valueStr.empty())
    {
        expressionStr = varNameStr + " = 1;";
    }
    else if(stringStartsWith(valueStr, "["))
    {
        valueStr = valueStr.substr(1, valueStr.length() - 2);
        vector<string> valueList = stringSplit(valueStr, ",");
        for(int i = 0; i < valueList.size(); i++)
        {
            expressionStr += varNameStr + "[" + to_string(i) + "] = " + valueList[i] + ";\n";
        }
    }
    else
    {
        expressionStr += varNameStr + " = " + valueStr + ";";
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
    return ret;
}

vector<ILLocalVariable> transLocalVariable()
{
    vector<ILLocalVariable> ret;
    if(actorInfo->outports.empty())
        return ret;

    
    ILLocalVariable temp;
    temp.name = actorInfo->name + "_" + actorInfo->outports[0]->name;
    temp.type = actorInfo->outports[0]->type;

    string valueStr = actorInfo->getParameterValueByName("Value");
    if(stringStartsWith(valueStr, "["))
    {
        valueStr = valueStr.substr(1, valueStr.length() - 2);
        vector<string> valueList = stringSplit(valueStr, ",");
        temp.arraySize.push_back(valueList.size());
    }


    ret.push_back(temp);

    return ret;
}

vector<StmtBatchCalculation> transExecBatchCalculation()
{
    vector<StmtBatchCalculation> ret;
    return ret;
}