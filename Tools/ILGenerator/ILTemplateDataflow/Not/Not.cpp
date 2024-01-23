#pragma once
#include "../BasicTemplate.h"

// 根据输入端口的数据源类型推断该组件所有端口的数据类型及数组长度



void transTypeInference()
{
    // 输入 actorInfo.inports.source
    // 输出 actorInfo.inports.type / arraySize
    // 输出 actorInfo.outports.type / arraySize
    if(actorInfo->inports.empty())
        return;
    for(int i = 0; i < actorInfo->outports.size(); i++)
    {
        CGTActorExeTransOutport* outport = actorInfo->outports[i];
        outport->type = "bool";
        outport->arraySize = actorInfo->inports[0]->arraySize;
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

    string expressionStr;
	expressionStr += actorInfo->name + "_" + actorInfo->outports[0]->name + " = ";
    expressionStr += "!" + getCGTActorExeTransSourceOutportVariableNameByName(actorInfo->inports[0]->sourceOutport);
    
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

    if(actorInfo->outports.empty() || actorInfo->inports.empty() || actorInfo->outports[0]->arraySize.empty())
        return ret;

    CGTActorExeTransOutport* outport = actorInfo->outports[0];
    StmtBatchCalculation stmt;
    stmt.operationType = StmtBatchCalculation::TypeLogicNot;
    stmt.dataType = outport->type;

    
    CGTActorExeTransInport* inport1 = actorInfo->inports[0];
    StmtBatchCalculation::StmtBatchCalculationInput stmtInput1;
    stmtInput1.name = getCGTActorExeTransSourceOutportVariableNameByName(inport1->sourceOutport);
    stmtInput1.type = inport1->type;
    stmtInput1.arraySize = inport1->arraySize;
    stmt.inputs.push_back(stmtInput1);


    StmtBatchCalculation::StmtBatchCalculationOutput stmtOutput;
    stmtOutput.name = actorInfo->name + "_" + outport->name;
    stmtOutput.type = outport->type;
    stmtOutput.arraySize = outport->arraySize;
    stmt.outputs.push_back(stmtOutput);

    ret.push_back(stmt);


    return ret;
}
