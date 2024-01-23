#pragma once
#include "../BasicTemplate.h"

// ��������˿ڵ�����Դ�����ƶϸ�������ж˿ڵ��������ͼ����鳤��

void transTypeInference()
{
    // ���� ActorInfo.inports.source
    // ��� retCalculateExec.inports.type / arraySize
    // ��� retCalculateExec.outports.type / arraySize

    transTypeInferenceBasic(Token::Add);
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

    
    string code;

    code += actorInfo->name + "_" + actorInfo->outports[0]->name + " = ";
    
    int count = 0;
    vector<string> src1NameSp = stringSplit(actorInfo->inports[0]->sourceOutport, ",");
    for(int i = 0; i < src1NameSp.size(); i++)
    {
        CGTActorExeTransSourceOutport* src = getCGTActorExeTransSourceOutportByName(actorInfo->inports[0]->sourceOutport, i);
        string var = getCGTActorExeTransSourceOutportVariableNameByPort(src);
        if(count > 0)
            code += " + ";
        code += var;

        count++;
    }
    if(actorInfo->inports.size() < 2)
    {
        code += ";\n";
        return code;
    }
    vector<string> src2NameSp = stringSplit(actorInfo->inports[1]->sourceOutport, ",");
    for(int i = 0; i < src2NameSp.size(); i++)
    {
        CGTActorExeTransSourceOutport* src = getCGTActorExeTransSourceOutportByName(actorInfo->inports[1]->sourceOutport, i);
        string var = getCGTActorExeTransSourceOutportVariableNameByPort(src);
        code += " - " + var;

        count++;
    }
    code += ";\n";
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
    return ret;
}

vector<ILLocalVariable> transLocalVariable()
{
    vector<ILLocalVariable> ret;

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
