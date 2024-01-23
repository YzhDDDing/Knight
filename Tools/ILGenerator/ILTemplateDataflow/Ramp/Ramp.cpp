#pragma once
#include "../BasicTemplate.h"


// ��������˿ڵ�����Դ�����ƶϸ�������ж˿ڵ��������ͼ����鳤��



void transTypeInference()
{
    // ���� actorInfo.inports.source
    // ��� actorInfo.inports.type / arraySize
    // ��� actorInfo.outports.type / arraySize
    
    transTypeInferenceBasic(Token::Unknow);

}


// ����װ���ʽ��ʣ����������BasicTemplate�й���

string transInitExpression()
{
    return "";
}

// ����װ���ʽ��ʣ����������BasicTemplate�й���

string transExecExpression()
{
    string code;
    
    string slope = actorInfo->getParameterValueByName("Slope");
    CGTActorExeTransOutport* outport = actorInfo->outports[0];
    code += actorInfo->name + "_" + outport->name + " = " + actorInfo->name + "_State;\n";
    code += actorInfo->name + "_State += " + slope + ";\n";

    return code;
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
    CGTActorExeTransOutport* outport = actorInfo->outports[0];
    ILGlobalVariable temp;
    temp.name = actorInfo->name + "_State";
    temp.type = outport->type;
    temp.arraySize = outport->arraySize;

    string defaultValue = actorInfo->getParameterValueByName("Start");
    ILExpressionParser expParser;
    temp.defaultValue = expParser.parseExpression(defaultValue);


    ret.push_back(temp);

    return ret;
}

vector<ILLocalVariable> transLocalVariable()
{
    vector<ILLocalVariable> ret;

    for(int i = 0; i < actorInfo->outports.size(); i++)
    {
        CGTActorExeTransOutport* outport = actorInfo->outports[i];
        ILLocalVariable temp;
        temp.name = actorInfo->name + "_" + outport->name;
        temp.type = outport->type;
        temp.arraySize = outport->arraySize;

        ret.push_back(temp);
    }

    return ret;
}

vector<StmtBatchCalculation> transExecBatchCalculation()
{
    vector<StmtBatchCalculation> ret;
    return ret;
}