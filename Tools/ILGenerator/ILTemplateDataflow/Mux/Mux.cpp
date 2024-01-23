#pragma once
#include "../BasicTemplate.h"


// ��������˿ڵ�����Դ�����ƶϸ�������ж˿ڵ��������ͼ����鳤��



void transTypeInference()
{
    // ���� actorInfo.inports.source
    // ��� actorInfo.inports.type / arraySize
    // ��� actorInfo.outports.type / arraySize
    
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