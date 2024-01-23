#pragma once
#include "../BasicTemplate.h"


// 根据输入端口的数据源类型推断该组件所有端口的数据类型及数组长度



void transTypeInference()
{
    // 输入 actorInfo.inports.source
    // 输出 actorInfo.inports.type / arraySize
    // 输出 actorInfo.outports.type / arraySize
    
    //transTypeInferenceBasic(Token::Mul);
    CGTActorExeTransOutport* outport = actorInfo->outports[0];
    outport->type = "f32";
}


// 仅组装表达式，剩余的在组件的BasicTemplate中构造

string transInitExpression()
{
    return "";
}

// 仅组装表达式，剩余的在组件的BasicTemplate中构造

string transExecExpression()
{
    string code;
    string frequencyValue = actorInfo->getParameterValueByName("Frequency");
    CGTActorExeTransOutport* outport = actorInfo->outports[0];
    code += actorInfo->name + "_" + outport->name + " = sin(" + actorInfo->name + "_State);\n";
    code += actorInfo->name + "_State += 6.2831852 * " +  frequencyValue + ";\n";

    return code;
}

// 无需添加下面各个IL返回值的ref

vector<ILHeadFile> transHeadFile()
{
    vector<ILHeadFile> ret;
    ILHeadFile temp;
    temp.name = "math";
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
    CGTActorExeTransOutport* outport = actorInfo->outports[0];
    ILGlobalVariable temp;
    temp.name = actorInfo->name + "_State";
    temp.type = "f32";

    string defaultValue = "0";
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