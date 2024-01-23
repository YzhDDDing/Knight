#pragma once
#include "../BasicTemplate.h"


// 根据输入端口的数据源类型推断该组件所有端口的数据类型及数组长度

void transTypeInference()
{
    // 输入 actorInfo.inports.source
    // 输出 actorInfo.inports.type / arraySize
    // 输出 actorInfo.outports.type / arraySize
    
    string outType;
    vector<int> outArraySize;
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
        outArraySize = inport->arraySize;
    }

    if(!actorInfo->outports.empty()) {
        CGTActorExeTransOutport* outport = actorInfo->outports[0];
        outport->type = getSimulinkOutDataType();
        if(outport->type == "#Default") {
            outport->type = outType;
        }
        if(outport->arraySize.empty()) {
            outport->arraySize = outArraySize;
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
    return "";
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
    if(actorInfo->outports.empty() || actorInfo->inports.empty() || actorInfo->inports[0]->arraySize.empty())
        return ret;
    CGTActorExeTransOutport* outport = actorInfo->outports[0];
    StmtBatchCalculation stmt;
    stmt.operationType = StmtBatchCalculation::TypeFFT;
    stmt.dataType = outport->type;

    
    CGTActorExeTransInport* inport = actorInfo->inports[0];
    StmtBatchCalculation::StmtBatchCalculationInput stmtInput;
    stmtInput.name = getCGTActorExeTransSourceOutportVariableNameByName(inport->sourceOutport);
    stmtInput.type = inport->type;
    stmtInput.arraySize = inport->arraySize;
    stmt.inputs.push_back(stmtInput);



    StmtBatchCalculation::StmtBatchCalculationOutput stmtOutput;
    stmtOutput.name = actorInfo->name + "_" + outport->name;
    stmtOutput.type = outport->type;
    stmtOutput.arraySize = outport->arraySize;
    stmt.outputs.push_back(stmtOutput);

    ret.push_back(stmt);

    return ret;
}