#pragma once
#include "../BasicTemplate.h"


// ��������˿ڵ�����Դ�����ƶϸ�������ж˿ڵ��������ͼ����鳤��



void transTypeInference()
{
    // ���� actorInfo.inports.source
    // ��� actorInfo.inports.type / arraySize
    // ��� actorInfo.outports.type / arraySize
    CGTActorExeTransOutport* outport = actorInfo->outports[0];
    if(outport->type == "#Default") {
        outport->type = "f32";
	}
}


// ����װ����ʽ��ʣ����������BasicTemplate�й���

string transInitExpression()
{
    return "";
}

// ����װ����ʽ��ʣ����������BasicTemplate�й���

string transExecExpression()
{
    if(actorInfo->outports.empty())
        return "";

    string expressionStr;
    expressionStr += actorInfo->name + "_" + actorInfo->outports[0]->name + " = ";
    
	expressionStr += actorInfo->getParameterValueByName("StateVariableName") + ";";
        //actorInfo->name.substr(0, actorInfo->name.length() - 5) + "_state;";

    return expressionStr;
}

// ���������������IL����ֵ��ref

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
    if(actorInfo->outports.empty())
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
    if(actorInfo->outports.empty() || actorInfo->outports[0]->arraySize.empty())
        return ret;
    //CGTActorExeTransOutport* outport = actorInfo->outports[0];
    StmtBatchCalculation stmt;
    stmt.operationType = StmtBatchCalculation::TypeReadData;
    
    CGTActorExeTransOutport* outport = actorInfo->outports[0];
    stmt.dataType = outport->type;
    StmtBatchCalculation::StmtBatchCalculationInput stmtInput;
    stmtInput.name = actorInfo->getParameterValueByName("StateVariableName");
    stmtInput.type = outport->type;
    stmtInput.arraySize = outport->arraySize;
    stmt.inputs.push_back(stmtInput);

    StmtBatchCalculation::StmtBatchCalculationOutput stmtOutput;
    stmtOutput.name = actorInfo->name + "_" + outport->name;
    stmtOutput.type = outport->type;
    stmtOutput.arraySize = outport->arraySize;
    stmt.outputs.push_back(stmtOutput);

    ret.push_back(stmt);

    return ret;
}