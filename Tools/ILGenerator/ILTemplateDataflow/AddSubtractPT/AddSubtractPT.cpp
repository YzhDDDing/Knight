#pragma once
#include "../BasicTemplate.h"

// 根据输入端口的数据源类型推断该组件所有端口的数据类型及数组长度

void transTypeInference()
{
    // 输入 ActorInfo.inports.source
    // 输出 retCalculateExec.inports.type / arraySize
    // 输出 retCalculateExec.outports.type / arraySize

    transTypeInferenceBasic(Token::Add);
}


// 仅组装表达式，剩余的在组件的BasicTemplate中构造

string transInitExpression()
{
    return "";
}

// 仅组装表达式，剩余的在组件的BasicTemplate中构造

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

// 无需添加下面各个IL返回值的ref

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
