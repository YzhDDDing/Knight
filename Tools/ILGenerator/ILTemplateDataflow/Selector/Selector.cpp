#pragma once
#include "../BasicTemplate.h"


// 根据输入端口的数据源类型推断该组件所有端口的数据类型及数组长度



void transTypeInference()
{
    // 输入 actorInfo.inports.source
    // 输出 actorInfo.inports.type / arraySize
    // 输出 actorInfo.outports.type / arraySize

    transTypeInferencePassInportFromSrc();
    
    CGTActorExeTransInport* inport = actorInfo->inports[0];
    CGTActorExeTransOutport* outport = actorInfo->outports[0];
    if(outport->type == "#Default") {
        outport->type = inport->type;
    }

    string indexOptions = actorInfo->getParameterValueByName("IndexOptions");
    if(indexOptions == "Index vector (dialog)")
    {
        outport->arraySize.clear();
    }
    else if(indexOptions == "Starting index (dialog)")
    {
        string outputSizesStr = actorInfo->getParameterValueByName("OutputSizes");
        if(!outputSizesStr.empty()) {
            outport->arraySize.clear();
            outport->arraySize.push_back(stringToInt(outputSizesStr));
        } else {
            outport->arraySize = inport->arraySize;
        }
    }
    else if (indexOptions == "Index vector (port)")
    {
        outport->type = inport->type;
    }
    else if (indexOptions == "Starting index (port)")
    {

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
    string ret;

    string indexOptions = actorInfo->getParameterValueByName("IndexOptions");
    string indexMode = actorInfo->getParameterValueByName("IndexMode");
    string indexStr = actorInfo->getParameterValueByName("Indices");
    if(indexStr.empty())
        indexStr = "0";
    else if(indexStr[0] == '[')
        indexStr = indexStr.substr(1,indexStr.length() - 2);
    int index = stringToInt(indexStr) - ((indexMode == "Zero-based") ? 0 : 1);
    indexStr = "[" + to_string(index) + "]";

    if(indexOptions == "Index vector (dialog)")
    {
        ret += actorInfo->name + "_" + actorInfo->outports[0]->name;
        ret += "=";
        ret += getCGTActorExeTransSourceOutportVariableNameByName(actorInfo->inports[0]->sourceOutport);
        ret += indexStr;
        ret += ";";
    }
    else if(indexOptions == "Starting index (dialog)")
    {

    }
    else if(indexOptions == "Index vector (port)")
    {
        ret += actorInfo->name + "_" + actorInfo->outports[0]->name;
        ret += "=";
        ret += getCGTActorExeTransSourceOutportVariableNameByName(actorInfo->inports[0]->sourceOutport);
        ret += "[";
        ret += getCGTActorExeTransSourceOutportVariableNameByName(actorInfo->inports[1]->sourceOutport);
        ret += "]";
        ret += ";";
    }
    else if (indexOptions == "Starting index (port)")
    {

    }

    return ret;
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

    string indexOptions = actorInfo->getParameterValueByName("IndexOptions");
    string indexMode = actorInfo->getParameterValueByName("IndexMode");
    string indexStr = actorInfo->getParameterValueByName("Indices");
    if (indexStr.empty())
        indexStr = "0";
    else if (indexStr[0] == '[')
        indexStr = indexStr.substr(1, indexStr.length() - 2);
    int index = stringToInt(indexStr) - ((indexMode == "Zero-based") ? 0 : 1);
    indexStr = "[" + to_string(index) + "]";

    if(indexOptions == "Index vector (dialog)")
    {
        
    }
    else if(indexOptions == "Starting index (dialog)")
    {
        temp.isAddress = 1;
        string valueExp = "&(";
        valueExp += getCGTActorExeTransSourceOutportVariableNameByName(actorInfo->inports[0]->sourceOutport);
        valueExp += indexStr;
        valueExp += ");";
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