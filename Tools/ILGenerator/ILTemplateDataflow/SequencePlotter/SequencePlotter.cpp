#pragma once
#include "../BasicTemplate.h"


// 根据输入端口的数据源类型推断该组件所有端口的数据类型及数组长度

void transTypeInference()
{
    // 输入 actorInfo.inports.source
    // 输出 actorInfo.inports.type / arraySize
    // 输出 actorInfo.outports.type / arraySize
    
    transTypeInferencePassInportFromSrc();
}


// 仅组装表达式，剩余的在组件的BasicTemplate中构造

string transInitExpression()
{
    return "";
}

// 仅组装表达式，剩余的在组件的BasicTemplate中构造

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

// 无需添加下面各个IL返回值的ref

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