#pragma once
#include "../BasicTemplate.h"


// 根据输入端口的数据源类型推断该组件所有端口的数据类型及数组长度



void transTypeInference()
{
    // 输入 actorInfo.inports.source
    // 输出 actorInfo.inports.type / arraySize
    // 输出 actorInfo.outports.type / arraySize
    
    for(int i = 0; i < actorInfo->outports.size(); i++)
    {
        CGTActorExeTransOutport* outport = actorInfo->outports[i];
        outport->type = "bool";
        outport->arraySize.clear();
    }

}


// 仅组装表达式，剩余的在组件的BasicTemplate中构造

string transInitExpression()
{
    return "";
}

// 仅组装表达式，剩余的在组件的BasicTemplate中构造

string transExecExpression()
{
    string condition = actorInfo->getParameterValueByName("IfExpression");
    if(condition.empty())
        condition = "u1 > 0";

    
    condition = stringReplaceAll(condition, "~=", "!=");
    condition = stringReplaceAll(condition, "&", "&&");
    condition = stringReplaceAll(condition, "|", "||");

    string numInputsStr = actorInfo->getParameterValueByName("NumInputs");
    if(numInputsStr.empty())
        numInputsStr = "1";
    int numInputs = stringToInt(numInputsStr);

    for(int i = 0; i < numInputs; i++)
    {
        string inputStr = "u" + to_string(i + 1);
        condition = stringReplaceAll(condition, inputStr, getCGTActorExeTransSourceOutportVariableNameByName(actorInfo->inports[i]->sourceOutport));
    }

    string code;

    CGTActorExeTransInport* inport = actorInfo->inports[0];

    for(int i = 0; i < actorInfo->outports.size(); i++)
    {
        CGTActorExeTransOutport* outport = actorInfo->outports[i];

        code += actorInfo->name + "_" + outport->name + " = ";
        code += (i == 0) ? "(" : "!(";

        code += condition;

        code += ");\n";
    }

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
    
    ILMacro boolDefine;
    boolDefine.name = "bool";
    boolDefine.value = "unsigned char";

    ret.push_back(boolDefine);

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