#pragma once
#include "../BasicTemplate.h"

#include <algorithm>

map<string, string> outputRedefineMap;
void parseOutputRedefine()
{
    vector<string> spStr = {"=>", "."};
    outputRedefineMap.clear();

    string para = actorInfo->getParameterValueByName("OutputRedefine");
    
    vector<string> redefineList = stringSplit(para, ";");
    for(int i = 0; i < redefineList.size(); i++)
    {
        if(redefineList[i].empty())
            continue;

        vector<string> varRedefine = stringSplit(redefineList[i], spStr);
        if(varRedefine.size() != 3)
            continue;

        string oriVarName = actorInfo->name + "_" + varRedefine[0];
        string dstVarName = varRedefine[1] + "_" + varRedefine[2];

        outputRedefineMap[oriVarName] = dstVarName;
    }
}

string getOutputVariableName(string oriOutputVar)
{
    if(outputRedefineMap.find(oriOutputVar) != outputRedefineMap.end())
    {
        return outputRedefineMap.at(oriOutputVar);
    }
    return oriOutputVar;
}


// 根据输入端口的数据源类型推断该组件所有端口的数据类型及数组长度

void transTypeInference()
{
    // 输入 actorInfo.inports.source
    // 输出 actorInfo.inports.type / arraySize
    // 输出 actorInfo.outports.type / arraySize

    for(int i = 0; i < actorInfo->inports.size(); i++)
    {
        CGTActorExeTransInport* inport = actorInfo->inports[i];
        if(inport->type == "#Default")
            inport->type = defaultType;
    }
    for(int i = 0; i < actorInfo->outports.size(); i++)
    {
        CGTActorExeTransOutport* outport = actorInfo->outports[i];
        if(outport->type == "#Default")
            outport->type = defaultType;
    }

}


// 仅组装表达式，剩余的在组件的BasicTemplate中构造

string transInitExpression()
{
    string functionName = actorInfo->getParameterValueByName("FunctionRef");
    string initCode;
    initCode += functionName + "_Init";
    initCode += "(";
    initCode += "&" + functionName + "_instance";
    initCode += ");";

    return initCode;
}

// 仅组装表达式，剩余的在组件的BasicTemplate中构造

string transExecExpression()
{
    parseOutputRedefine();

    CGTActorExeTransActionPort* ifActionPort = nullptr;
    CGTActorExeTransActionPort* enablePort = nullptr;
    for(int i = 0; i < actorInfo->actionPorts.size(); i++) {
        if(actorInfo->actionPorts[i]->type == "IfAction"){
            ifActionPort = actorInfo->actionPorts[i];
        } else if(actorInfo->actionPorts[i]->type == "Enable"){
            enablePort = actorInfo->actionPorts[i];
        }
    }

    string functionName = actorInfo->getParameterValueByName("FunctionRef");
    string exeCode;
    exeCode += functionName + "_Update";
    exeCode += "(";
    exeCode += "&" + functionName + "_instance, ";
    for(int i = 0; i < actorInfo->inports.size(); i++)
    {
        CGTActorExeTransInport* inport = actorInfo->inports[i];
        exeCode += getCGTActorExeTransSourceOutportVariableNameByName(inport->sourceOutport);
        exeCode += ", ";
    }
    for(int i = 0; i < actorInfo->outports.size(); i++)
    {
        CGTActorExeTransOutport* outport = actorInfo->outports[i];
        exeCode += outport->arraySize.empty() ? "&" : "";
        exeCode += getOutputVariableName(actorInfo->name + "_" + outport->name);
        exeCode += ", ";
    }
    //if(actorInfo->inports.size() + actorInfo->outports.size() > 0)
    {
        exeCode = exeCode.substr(0, exeCode.length() - 2);
    }
    exeCode += ");";

    string code;


    if(ifActionPort || enablePort)
    {
        string conditionStr;
        if(ifActionPort) {
            conditionStr = getCGTActorExeTransSourceOutportVariableNameByName(ifActionPort->sourceOutport);
        } else if(enablePort) {
            conditionStr = getCGTActorExeTransSourceOutportVariableNameByName(enablePort->sourceOutport);
            conditionStr += " > 0";
        }
        code += "if(" + conditionStr + "){\n";
        code += exeCode + "\n";
        code += "}";
    }
    else
    {
        code += exeCode;
    }


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

namespace
{
    vector<string> parameterNoNeedToGenerate = {
        "FunctionRef",
        "OutputRedefine",
        "TreatAsAtomicUnit",
    };
}

vector<ILMacro> transMacro()
{
    vector<ILMacro> ret;

    //string functionName = actorInfo->getParameterValueByName("FunctionRef");

    for(int i = 0; i < actorInfo->parameters.size(); i++)
    {
        CGTActorExeTransParameter* parameter = actorInfo->parameters[i];
        if(find(parameterNoNeedToGenerate.begin(), parameterNoNeedToGenerate.end(), parameter->name) != parameterNoNeedToGenerate.end())
            continue;

        ILMacro temp;
        temp.name = parameter->name;
        temp.value = parameter->value;
        ret.push_back(temp);
    }

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
    parseOutputRedefine();

    vector<ILLocalVariable> ret;

    for(int i = 0; i < actorInfo->outports.size(); i++)
    {
        CGTActorExeTransOutport* outport = actorInfo->outports[i];
        ILLocalVariable temp;
        temp.name = actorInfo->name + "_" + outport->name;
        temp.type = outport->type;
        temp.arraySize = outport->arraySize;

        if(temp.name != getOutputVariableName(temp.name))
            continue;

        ret.push_back(temp);
    }

    return ret;
}

vector<StmtBatchCalculation> transExecBatchCalculation()
{
    vector<StmtBatchCalculation> ret;
    
    return ret;
}