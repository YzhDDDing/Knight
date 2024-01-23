#pragma once
#include "../BasicTemplate.h"
#include "../../../../Src/ILBasic/StmtIf.h"
#include "../../../../Src/ILBasic/StmtElse.h"


// 根据输入端口的数据源类型推断该组件所有端口的数据类型及数组长度



void transTypeInference()
{
    // 输入 actorInfo.inports.source
    // 输出 actorInfo.inports.type / arraySize
    // 输出 actorInfo.outports.type / arraySize
    transTypeInferenceOutportSameAsInport(0);

    
    CGTActorExeTransOutport* outport = actorInfo->outports[0];
    for(int i = 0; i < actorInfo->inports.size(); i++)
    {
        if(outport->arraySize.empty() && !actorInfo->inports[i]->arraySize.empty())
        {
            outport->arraySize = actorInfo->inports[i]->arraySize;
        }
    }

}


// 仅组装表达式，剩余的在组件的BasicTemplate中构造

string transInitExpression()
{
    return "";
}

// 仅组装表达式，剩余的在组件的BasicTemplate中构造

// 由于Switch组件需要if判断和赋值运算(可能为批量)结合，所以当输入为数组时直接构造calculateExec的Stmt
string transExecExpression()
{
    if(actorInfo->inports.size() != 3)
        return "";

    
    string expressionStr;
    string arrayIndexStr = "";
    if(!actorInfo->inports[1]->arraySize.empty())
    {
        expressionStr += "for(";
        expressionStr += "int " + actorInfo->name + "_i = 0; ";
        expressionStr += actorInfo->name + "_i <" + to_string(actorInfo->inports[1]->arraySize[0]) + "; ";
        expressionStr += actorInfo->name + "_i++){\n";

        arrayIndexStr = "[" + actorInfo->name + "_i]";
    }


    string criteria = actorInfo->getParameterValueByName("Criteria");
    string threshold = actorInfo->getParameterValueByName("Threshold");
    threshold = threshold.empty() ? "0" : threshold;
    string conditionStr;
    conditionStr += getCGTActorExeTransSourceOutportVariableNameByName(actorInfo->inports[1]->sourceOutport) + arrayIndexStr;
    if(criteria == "u2 > Threshold") {
        conditionStr += ">"; 
        conditionStr += threshold;
    } else if(criteria == "") {
        conditionStr += ">="; 
        conditionStr += threshold;
    } else if(criteria == "u2 ~= 0") {
        conditionStr += "!=0"; 
    }
    expressionStr += "if(";
    expressionStr += conditionStr;
    expressionStr += "){\n";
    expressionStr += actorInfo->name + "_" + actorInfo->outports[0]->name + arrayIndexStr;
    expressionStr += "=";
    expressionStr += getCGTActorExeTransSourceOutportVariableNameByName(actorInfo->inports[0]->sourceOutport);
    if(!actorInfo->inports[0]->arraySize.empty())
        expressionStr += arrayIndexStr;
    expressionStr += ";\n";
    expressionStr += "}\n";
    expressionStr += "else {\n";
    expressionStr += actorInfo->name + "_" + actorInfo->outports[0]->name + arrayIndexStr;
    expressionStr += "=";
    expressionStr += getCGTActorExeTransSourceOutportVariableNameByName(actorInfo->inports[2]->sourceOutport);
    if(!actorInfo->inports[2]->arraySize.empty())
        expressionStr += arrayIndexStr;
    expressionStr += ";\n";
    expressionStr += "}\n";

    if(!actorInfo->inports[1]->arraySize.empty())
    {
        expressionStr += "}";
    }

    return expressionStr;



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
    if(actorInfo->inports.empty())
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