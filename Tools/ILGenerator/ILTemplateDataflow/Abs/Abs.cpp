#pragma once
#include "../BasicTemplate.h"


// ��������˿ڵ�����Դ�����ƶϸ�������ж˿ڵ��������ͼ����鳤��



void transTypeInference()
{
    // ���� actorInfo.inports.source
    // ��� actorInfo.inports.type / arraySize
    // ��� actorInfo.outports.type / arraySize

    transTypeInferencePassInportFromSrc();
    actorInfo->outports[0]->type = actorInfo->inports[0]->type;
    string simulinkType = getSimulinkOutDataType();
    if(simulinkType != "#Default")
        actorInfo->outports[0]->type = simulinkType;
    actorInfo->outports[0]->arraySize = actorInfo->inports[0]->arraySize;
}


// ����װ���ʽ��ʣ����������BasicTemplate�й���

string transInitExpression()
{
    return "";
}

// ����װ���ʽ��ʣ����������BasicTemplate�й���

string transExecExpression()
{
    if(actorInfo->inports.empty())
        return "";

    string expressionStr;
	expressionStr += actorInfo->name + "_" + actorInfo->outports[0]->name + " = ";

    if(actorInfo->inports[0]->type == "f32" || actorInfo->inports[0]->type == "f64")
        expressionStr += "fabs(";
    else
        expressionStr += "abs(";
    expressionStr += getCGTActorExeTransSourceOutportVariableNameByName(actorInfo->inports[0]->sourceOutport);
    expressionStr += ")";
    
    expressionStr += ";";

    return expressionStr;
}

// ��������������IL����ֵ��ref

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
    if(actorInfo->inports.size() != 1 || 
        actorInfo->inports[0]->arraySize.empty())
        return ret;
    CGTActorExeTransOutport* outport = actorInfo->outports[0];
    StmtBatchCalculation stmt;

    stmt.operationType = StmtBatchCalculation::TypeAbs;
    stmt.dataType = outport->type;

    
    CGTActorExeTransInport* inport1 = actorInfo->inports[0];
    StmtBatchCalculation::StmtBatchCalculationInput stmtInput1;
    stmtInput1.name = getCGTActorExeTransSourceOutportVariableNameByName(inport1->sourceOutport);
    stmtInput1.type = inport1->type;
    stmtInput1.arraySize = inport1->arraySize;
    stmt.inputs.push_back(stmtInput1);

    //CGTActorExeTransInport* inport2 = actorInfo->inports[1];
    //StmtBatchCalculation::StmtBatchCalculationInput stmtInput2;
    //stmtInput2.name = getCGTActorExeTransSourceOutportVariableNameByName(inport2->sourceOutport);
    //stmtInput2.type = inport2->type;
    //stmtInput2.arraySize = inport2->arraySize;
    //stmt.inputs.push_back(stmtInput2);


    StmtBatchCalculation::StmtBatchCalculationOutput stmtOutput;
    stmtOutput.name = actorInfo->name + "_" + outport->name;
    stmtOutput.type = outport->type;
    stmtOutput.arraySize = outport->arraySize;
    stmt.outputs.push_back(stmtOutput);

    ret.push_back(stmt);

    return ret;
}