#pragma once
#include "../BasicTemplate.h"

vector<string> getMulOrDivSymbol(CGTActorExeTransActorInfo* actorInfo);

// 根据输入端口的数据源类型推断该组件所有端口的数据类型及数组长度



void transTypeInference()
{
    // 输入 actorInfo.inports.source
    // 输出 actorInfo.inports.type / arraySize
    // 输出 actorInfo.outports.type / arraySize
    
    transTypeInferenceBasic(Token::Mul);

}


// 仅组装表达式，剩余的在组件的BasicTemplate中构造

string transInitExpression()
{
    return "";
}

// 仅组装表达式，剩余的在组件的BasicTemplate中构造

bool charIsWord(char c)
{
    if(c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z' || c >= '0' && c <= '9')
        return true;
    return false;
}

string transExecExpression()
{
    if(actorInfo->outports.empty())
        return "";
    string expStr = actorInfo->getParameterValueByName("Expression");
    for (int i = 0; i < actorInfo->inports.size(); i++) {

        CGTActorExeTransInport* inport = actorInfo->inports[i];
        string srcVarName = getCGTActorExeTransSourceOutportVariableNameByName(actorInfo->inports[i]->sourceOutport);
        string portName = inport->name;
        int portNameLen = portName.length();
        size_t pos = expStr.find(portName, 0);
        while(pos != string::npos)
        {
            if((pos == 0 || !charIsWord(expStr[pos - 1])) &&
                (pos + portNameLen >= expStr.length() || !charIsWord(expStr[pos + portNameLen])))
            {
                expStr.replace(pos, portNameLen, srcVarName);
            }
            pos += srcVarName.length();
            pos = expStr.find(portName, pos);
        }
	}


    string expressionStr;
	expressionStr += actorInfo->name + "_" + actorInfo->outports[0]->name + " = ";
    expressionStr += expStr + ";\n";
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
