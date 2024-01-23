#pragma once
#include "../BasicTemplate.h"


// 根据输入端口的数据源类型推断该组件所有端口的数据类型及数组长度



void transTypeInference()
{
    // 输入 actorInfo.inports.source
    // 输出 actorInfo.inports.type / arraySize
    // 输出 actorInfo.outports.type / arraySize
    
    transTypeInferencePassInportFromSrc();

    string outType;
    int outArraySize = 0;
    for(int i = 0; i < actorInfo->inports.size(); i++) {
        CGTActorExeTransInport* inport = actorInfo->inports[i];
        CGTActorExeTransSourceOutport* src = getCGTActorExeTransSourceOutportByName(inport->sourceOutport);
        if(inport->type == "#Default") {
            inport->type = src->type;
        }
        if(inport->arraySize.empty()) {
            inport->arraySize = src->arraySize;
            outArraySize += 1;
        }
        else
        {
            outArraySize += inport->arraySize[0];
        }
        if(outType.empty()){
            outType = inport->type;
        } else {
            outType = BasicTypeCalculator::getExpResultType(outType == "#Default" ? defaultType: outType, inport->type == "#Default" ? defaultType: inport->type, Token::Add);
        }
    }

    if(!actorInfo->outports.empty())
    {
        CGTActorExeTransOutport* outport = actorInfo->outports[0];
        outport->type = getSimulinkOutDataType();
        if(outport->type == "#Default") {
            outport->type = outType;
        }
        outport->arraySize.push_back(outArraySize);
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
    if(actorInfo->outports.empty())
        return "";

    string expressionStr;

    int index = 0;
    for(int i = 0; i < actorInfo->inports.size(); i++)
    {
        CGTActorExeTransInport* inport = actorInfo->inports[i];
        if(inport->sourceOutport.empty())
            continue;
        if(actorInfo->inports[i]->arraySize.empty())
        {
            expressionStr += actorInfo->name + "_" + actorInfo->outports[0]->name;
            expressionStr +=  "[" + to_string(index) + "] = ";
            expressionStr += getCGTActorExeTransSourceOutportVariableNameByName(inport->sourceOutport);
            expressionStr += ";\n";
            index++;
        }
        else
        {
            for(int j = 0; j < actorInfo->inports[i]->arraySize[0]; j++)
            {
                expressionStr += actorInfo->name + "_" + actorInfo->outports[0]->name;
                expressionStr +=  "[" + to_string(index) + "] = ";
                expressionStr += getCGTActorExeTransSourceOutportVariableNameByName(inport->sourceOutport);
                expressionStr +=  "[" + to_string(j) + "]";
                expressionStr += ";\n";
                index++;
            }
        }
        
    }
    
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