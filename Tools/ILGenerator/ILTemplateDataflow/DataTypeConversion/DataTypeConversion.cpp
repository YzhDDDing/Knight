#pragma once
#include "../BasicTemplate.h"

vector<string> getMulOrDivSymbol(CGTActorExeTransActorInfo* actorInfo);

// 根据输入端口的数据源类型推断该组件所有端口的数据类型及数组长度



void transTypeInference()
{
    // 输入 actorInfo.inports.source
    // 输出 actorInfo.inports.type / arraySize
    // 输出 actorInfo.outports.type / arraySize
    
    //transTypeInferenceBasic(Token::Mul);
    transTypeInferenceOutportSameAsInport();
    string outputTypeStr = actorInfo->getParameterValueByName("OutDataTypeStr");
    if(!outputTypeStr.empty())
        actorInfo->outports[0]->type = getSimpleDataTypeFromSimulinkType(outputTypeStr);
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
	expressionStr += actorInfo->name + "_" + actorInfo->outports[0]->name + " = ";

    string inportType = actorInfo->inports[0]->type;
    string outportType = actorInfo->outports[0]->type;
    if(inportType != outportType)
    {
        expressionStr += "(" + getCodeDataTypeFromSimpleType(outportType) + ")(";
    }
    expressionStr += getCGTActorExeTransSourceOutportVariableNameByName(actorInfo->inports[0]->sourceOutport);
    if(inportType != outportType)
    {
        expressionStr += ")";
    }
    expressionStr += ";";

    return expressionStr;
}

// 无需添加下面各个IL返回值的ref

vector<ILHeadFile> transHeadFile()
{
    vector<ILHeadFile> ret;
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
