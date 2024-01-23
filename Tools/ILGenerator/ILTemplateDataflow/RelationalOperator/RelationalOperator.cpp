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
    if(actorInfo->outports.empty() || actorInfo->inports.size() != 2)
        return "";

    string para = actorInfo->getParameterValueByName("Operator");
    if(para == "~=")
        para = "!=";
    else if(para == "")
        para = ">=";

    string code;

    CGTActorExeTransOutport* outport = actorInfo->outports[0];

    CGTActorExeTransInport* inport1 = actorInfo->inports[0];
    CGTActorExeTransInport* inport2 = actorInfo->inports[1];

    code += actorInfo->name + "_" + outport->name + " = ";
    code += getCGTActorExeTransSourceOutportVariableNameByName(inport1->sourceOutport);
    code += " " + para + " ";
    code += getCGTActorExeTransSourceOutportVariableNameByName(inport2->sourceOutport);
    code += ";\n";

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

map<string, StmtBatchCalculation::OperationType> operatorMap = {
    pair<string, StmtBatchCalculation::OperationType>("<", StmtBatchCalculation::TypeLess),
    pair<string, StmtBatchCalculation::OperationType>("<=", StmtBatchCalculation::TypeLessEqual),
    pair<string, StmtBatchCalculation::OperationType>(">", StmtBatchCalculation::TypeGreater),
    pair<string, StmtBatchCalculation::OperationType>(">=", StmtBatchCalculation::TypeGreaterEqual),
    pair<string, StmtBatchCalculation::OperationType>("==", StmtBatchCalculation::TypeEqual),
    pair<string, StmtBatchCalculation::OperationType>("~=", StmtBatchCalculation::TypeNotEqual),
};

vector<StmtBatchCalculation> transExecBatchCalculation()
{
    vector<StmtBatchCalculation> ret;
    if(actorInfo->outports.empty() || actorInfo->inports.empty() || actorInfo->outports[0]->arraySize.empty())
        return ret;
    CGTActorExeTransOutport* outport = actorInfo->outports[0];
    StmtBatchCalculation stmt;
    string para = actorInfo->getParameterValueByName("Operator");
    stmt.operationType = operatorMap.at(para);
    stmt.dataType = outport->type;

    
    CGTActorExeTransInport* inport1 = actorInfo->inports[0];
    StmtBatchCalculation::StmtBatchCalculationInput stmtInput1;
    stmtInput1.name = getCGTActorExeTransSourceOutportVariableNameByName(inport1->sourceOutport);
    stmtInput1.type = inport1->type;
    stmtInput1.arraySize = inport1->arraySize;
    stmt.inputs.push_back(stmtInput1);

    CGTActorExeTransInport* inport2 = actorInfo->inports[1];
    StmtBatchCalculation::StmtBatchCalculationInput stmtInput2;
    stmtInput2.name = getCGTActorExeTransSourceOutportVariableNameByName(inport2->sourceOutport);
    stmtInput2.type = inport2->type;
    stmtInput2.arraySize = inport2->arraySize;
    stmt.inputs.push_back(stmtInput2);


    StmtBatchCalculation::StmtBatchCalculationOutput stmtOutput;
    stmtOutput.name = actorInfo->name + "_" + outport->name;
    stmtOutput.type = outport->type;
    stmtOutput.arraySize = outport->arraySize;
    stmt.outputs.push_back(stmtOutput);

    ret.push_back(stmt);

    return ret;
}