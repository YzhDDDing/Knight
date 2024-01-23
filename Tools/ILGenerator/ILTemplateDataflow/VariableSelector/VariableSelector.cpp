#pragma once
#include "../BasicTemplate.h"


// 根据输入端口的数据源类型推断该组件所有端口的数据类型及数组长度



void transTypeInference()
{
    // 输入 actorInfo.inports.source
    // 输出 actorInfo.inports.type / arraySize
    // 输出 actorInfo.outports.type / arraySize
    
    string outType;
    if(!actorInfo->inports.empty()) {
        CGTActorExeTransInport* inport = actorInfo->inports[0];
        CGTActorExeTransSourceOutport* src = getCGTActorExeTransSourceOutportByName(inport->sourceOutport);
        if(inport->type == "#Default") {
            inport->type = src->type;
        }
        if(inport->arraySize.empty()) {
            inport->arraySize = src->arraySize;
        }
        string inputPortWidthStr = actorInfo->getParameterValueByName("InputPortWidth");
        if(!inputPortWidthStr.empty()) {
            inport->arraySize.clear();
            inport->arraySize.push_back(stringToInt(inputPortWidthStr));
        }
        outType = inport->type;
    }

    if(!actorInfo->outports.empty())
    {
        CGTActorExeTransOutport* outport = actorInfo->outports[0];
        outport->type = getSimulinkOutDataType();
        if(outport->type == "#Default") {
            outport->type = outType;
        }
        string outputSizesStr = actorInfo->getParameterValueByName("OutputSizes");
        if(!outputSizesStr.empty()) {
            outport->arraySize.clear();
            outport->arraySize.push_back(stringToInt(outputSizesStr));
        }
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
    if(actorInfo->outports.empty() || actorInfo->inports.empty())
        return "";

    CGTActorExeTransInport* inport = actorInfo->inports[0];
    string indexStr = actorInfo->getParameterValueByName("Elements");
    if(indexStr.empty())
        indexStr = "0";
    
    string expressionStr;
	expressionStr += actorInfo->name + "_" + actorInfo->outports[0]->name + " = ";
    expressionStr += getCGTActorExeTransSourceOutportVariableNameByName(inport->sourceOutport);
    expressionStr += "[" + indexStr + "];";
    
    return expressionStr;
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
    if(actorInfo->outports.empty() || actorInfo->inports.empty())
        return ret;

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