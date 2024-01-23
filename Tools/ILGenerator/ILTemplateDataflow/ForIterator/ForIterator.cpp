#pragma once
#include "../BasicTemplate.h"


// 根据输入端口的数据源类型推断该组件所有端口的数据类型及数组长度



void transTypeInference()
{
    // 输入 ActorInfo.inports.source
    // 输出 ActorInfo.inports.type / arraySize
    // 输出 ActorInfo.outports.type / arraySize
    string type;
    if(!actorInfo->outports.empty())
        type = getSimulinkOutDataType();
    if(type == "#Default")
        type = "i32";
    actorInfo->outports[0]->type = type;

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
    string varNameStr;
	varNameStr += actorInfo->name + "_" + actorInfo->outports[0]->name;

    expressionStr += varNameStr + " ++;";
    
    


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
    if(actorInfo->outports.empty())
        return ret;

    
    ILLocalVariable temp;
    temp.name = actorInfo->name + "_" + actorInfo->outports[0]->name;
    temp.type = actorInfo->outports[0]->type;
    string defaultValue = "0";
    string indexModeStr = actorInfo->getParameterValueByName("IndexMode");
    if(indexModeStr == "Zero-based")
        defaultValue = "-1";
    ILExpressionParser expParser;
    temp.defaultValue = expParser.parseExpression(defaultValue);

    ret.push_back(temp);

    return ret;
}

vector<StmtBatchCalculation> transExecBatchCalculation()
{
    vector<StmtBatchCalculation> ret;
    return ret;
}