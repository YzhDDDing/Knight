#pragma once
#include "../BasicTemplate.h"


// ��������˿ڵ�����Դ�����ƶϸ�������ж˿ڵ��������ͼ����鳤��

void transTypeInference()
{
    // ���� actorInfo.inports.source
    // ��� actorInfo.inports.type / arraySize
    // ��� actorInfo.outports.type / arraySize
    
    transTypeInferencePassInportFromSrc();
}


// ����װ���ʽ��ʣ����������BasicTemplate�й���

string transInitExpression()
{
    return "";
}

// ����װ���ʽ��ʣ����������BasicTemplate�й���

namespace
{
    std::map<string, string> printfTypeMap = {
        pair<string, string>("f32", "f"),
        pair<string, string>("f64", "lf"),
        pair<string, string>("i8", "d"),
        pair<string, string>("i16", "d"),
        pair<string, string>("i32", "d"),
        pair<string, string>("i64", "lld"),
        pair<string, string>("u8", "d"),
        pair<string, string>("u16", "d"),
        pair<string, string>("u32", "d"),
        pair<string, string>("u64", "lld"),
    };
}

string transExecExpression()
{
    string code;

    

    vector<string> srcNameSp = stringSplit(actorInfo->inports[0]->sourceOutport, ",");

    code += "printf(\"" + actorInfo->name + ": ";
    int count = 0;
    string varListCode;
    for(int i = 0; i < srcNameSp.size(); i++)
    {
        CGTActorExeTransSourceOutport* src = getCGTActorExeTransSourceOutportByName(actorInfo->inports[0]->sourceOutport, i);
        if(printfTypeMap.find(src->type) == printfTypeMap.end())
            continue;
        string printfType = printfTypeMap.at(src->type);
        if(count > 0)
            code += ", ";
        code += "%" + printfType;

        string var = getCGTActorExeTransSourceOutportVariableNameByPort(src);
        if(count > 0)
            varListCode += ", ";
        varListCode += var;

        count++;
    }
    if(count == 0)
        code += "\\n\");\n";
    else
        code += "\\n\", " + varListCode + ");\n";
    return code;
}

// ��������������IL����ֵ��ref

vector<ILHeadFile> transHeadFile()
{
    vector<ILHeadFile> ret;
    ILHeadFile temp;
    temp.name = "stdio";
    ret.push_back(temp);
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
    return ret;
}

vector<StmtBatchCalculation> transExecBatchCalculation()
{
    vector<StmtBatchCalculation> ret;
    return ret;
}