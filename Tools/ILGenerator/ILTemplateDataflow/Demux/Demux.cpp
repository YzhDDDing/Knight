#pragma once
#include "../BasicTemplate.h"


// 根据输入端口的数据源类型推断该组件所有端口的数据类型及数组长度



void transTypeInference()
{
    // 输入 actorInfo.inports.source
    // 输出 actorInfo.inports.type / arraySize
    // 输出 actorInfo.outports.type / arraySize
    CGTActorExeTransInport* inport = actorInfo->inports[0];
    
    CGTActorExeTransSourceOutport* srcOutport = getCGTActorExeTransSourceOutportByName(inport->sourceOutport);
    if(srcOutport->actorType == "FunctionCallGenerator")
        return;

    transTypeInferencePassInportFromSrc();

    int elementSize = inport->arraySize.empty() ? 1 : inport->arraySize[0];

    int elementSizeLast = elementSize - (int)(elementSize / actorInfo->outports.size()) * actorInfo->outports.size();
    
    for(int i = 0; i < actorInfo->outports.size(); i++)
    {
        CGTActorExeTransOutport* outport = actorInfo->outports[i];
        outport->type = inport->type;
        int arraySize = elementSize / actorInfo->outports.size() + (i < elementSizeLast ? 1 : 0);
        if(arraySize > 1)
            outport->arraySize.push_back(arraySize);
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
    
    CGTActorExeTransInport* inport = actorInfo->inports[0];
    
    CGTActorExeTransSourceOutport* srcOutport = getCGTActorExeTransSourceOutportByName(inport->sourceOutport);
    if(srcOutport->actorType == "FunctionCallGenerator")
        return "";

    string expressionStr;
    
    int index = 0;
    for(int i = 0; i < actorInfo->outports.size(); i++)
    {
        CGTActorExeTransOutport* outport = actorInfo->outports[i];
        
        if(outport->arraySize.empty())
        {
            expressionStr += actorInfo->name + "_" + outport->name;
            expressionStr +=  " = ";
            expressionStr += getCGTActorExeTransSourceOutportVariableNameByName(inport->sourceOutport);
            expressionStr +=  "[" + to_string(index) + "]";
            expressionStr += ";\n";
            index++;
        }
        else
        {
            for(int j = 0; j < outport->arraySize[0]; j++)
            {
                expressionStr += actorInfo->name + "_" + outport->name;
                expressionStr +=  "[" + to_string(j) + "] = ";
                expressionStr += getCGTActorExeTransSourceOutportVariableNameByName(inport->sourceOutport);
                expressionStr +=  "[" + to_string(index) + "]";
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

    
    CGTActorExeTransInport* inport = actorInfo->inports[0];
    
    CGTActorExeTransSourceOutport* srcOutport = getCGTActorExeTransSourceOutportByName(inport->sourceOutport);
    if(srcOutport->actorType == "FunctionCallGenerator")
        return ret;

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