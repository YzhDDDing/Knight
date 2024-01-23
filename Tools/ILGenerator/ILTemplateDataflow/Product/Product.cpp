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

string transExecExpression()
{
    if(actorInfo->outports.empty())
        return "";

    string expressionStr;
	expressionStr += actorInfo->name + "_" + actorInfo->outports[0]->name + " = ";
    vector<string> symbols = getMulOrDivSymbol(actorInfo);
    int mulCount = 0;
	for (int i = 0; i < actorInfo->inports.size(); i++) {
        auto inport = actorInfo->inports[i];
		if(symbols[i] != "*")
            continue;
        if(mulCount != 0)
            expressionStr += " " + symbols[i] + " ";
        expressionStr += getCGTActorExeTransSourceOutportVariableNameByName(inport->sourceOutport);
        mulCount++;
	}
    if(mulCount == 0 && symbols.size() > 0)
    {
        expressionStr += "1";
    }
    if(mulCount < symbols.size())
    {
        for (int i = 0; i < actorInfo->inports.size(); i++) {
            auto inport = actorInfo->inports[i];
		    if(symbols[i] != "/")
                continue;
            expressionStr += " " + symbols[i] + " ";
            expressionStr += getCGTActorExeTransSourceOutportVariableNameByName(inport->sourceOutport);
	    }
    }
    if(actorInfo->inports.empty()) {
        expressionStr = expressionStr.substr(0, expressionStr.length() - 3) + ";";
    } else {
        expressionStr += ";";
    }
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
    
    for(int i = 2; i < actorInfo->inports.size(); i++)
    {
        ILLocalVariable batchTempVarVar;
        batchTempVarVar.name = actorInfo->name + "_" +  "BatchTempVar" + (actorInfo->inports.size() == 3 ? "" : to_string(i-1));
        batchTempVarVar.type = actorInfo->outports[0]->type;
        batchTempVarVar.arraySize = actorInfo->outports[0]->arraySize;

        ret.push_back(batchTempVarVar);
    }

    return ret;
}

vector<StmtBatchCalculation> transExecBatchCalculation()
{
    vector<StmtBatchCalculation> ret;
    if(actorInfo->outports.empty() || actorInfo->inports.empty() || actorInfo->outports[0]->arraySize.empty())
        return ret;

    CGTActorExeTransOutport* outport = actorInfo->outports[0];
    string lastTempVarName = getCGTActorExeTransSourceOutportVariableNameByName(actorInfo->inports[0]->sourceOutport);
    string lastTempVarType = actorInfo->inports[0]->type;
    vector<int> lastTempVarArraySize = actorInfo->inports[0]->arraySize;
    string lastTempVarDefaultValue;
    
    vector<string> symbols = getMulOrDivSymbol(actorInfo);
    int mulCount = 0;
	for (int i = 0; i < actorInfo->inports.size(); i++) {
        auto inport = actorInfo->inports[i];
		if(symbols[i] != "*")
            continue;
        if(mulCount == 0)
        {
            lastTempVarName = getCGTActorExeTransSourceOutportVariableNameByName(inport->sourceOutport);
            lastTempVarType = inport->type;
            lastTempVarArraySize = inport->arraySize;
        }
        else
        {
            StmtBatchCalculation stmt;
            stmt.operationType = StmtBatchCalculation::TypeMul;
            stmt.dataType = outport->type;

            StmtBatchCalculation::StmtBatchCalculationInput stmtInput1;
            stmtInput1.name = lastTempVarName;
            stmtInput1.type = lastTempVarType;
            stmtInput1.arraySize = lastTempVarArraySize;
            stmt.inputs.push_back(stmtInput1);

            StmtBatchCalculation::StmtBatchCalculationInput stmtInput2;
            stmtInput2.name = getCGTActorExeTransSourceOutportVariableNameByName(inport->sourceOutport);
            stmtInput2.type = inport->type;
            stmtInput2.arraySize = inport->arraySize;
            stmt.inputs.push_back(stmtInput2);


            StmtBatchCalculation::StmtBatchCalculationOutput stmtOutput;
            if(i == actorInfo->inports.size() - 1)
            {
                stmtOutput.name = actorInfo->name + "_" + outport->name;
                stmtOutput.type = outport->type;
                stmtOutput.arraySize = outport->arraySize;
            }
            else
            {
                lastTempVarName = actorInfo->name + "_" +  "BatchTempVar" + (actorInfo->inports.size() == 3 ? "" : to_string(mulCount));
                lastTempVarType = outport->type;
                lastTempVarArraySize = outport->arraySize;
                //if(stmtInput2.arraySize.size() > lastTempVarArraySize.size())
                //    lastTempVarArraySize = stmtInput2.arraySize;

                stmtOutput.name = lastTempVarName;
                stmtOutput.type = lastTempVarType;
                stmtOutput.arraySize = lastTempVarArraySize;
            }
            stmt.outputs.push_back(stmtOutput);

            ret.push_back(stmt);
        }
        mulCount++;
	}
    if(mulCount == 0 && symbols.size() > 0)
    {
        lastTempVarName = "";
        lastTempVarType = outport->type;
        lastTempVarArraySize.clear();
        lastTempVarDefaultValue = "1";
    }
    int divCount = 0;
    if(mulCount < symbols.size())
    {
        for (int i = 0; i < actorInfo->inports.size(); i++) {
            auto inport = actorInfo->inports[i];
		    if(symbols[i] != "/")
                continue;

            StmtBatchCalculation stmt;
            stmt.operationType = StmtBatchCalculation::TypeDiv;
            stmt.dataType = outport->type;

            StmtBatchCalculation::StmtBatchCalculationInput stmtInput1;
            stmtInput1.name = lastTempVarName;
            stmtInput1.type = lastTempVarType;
            stmtInput1.arraySize = lastTempVarArraySize;
            if(!lastTempVarDefaultValue.empty())
            {
                ILExpressionParser expressionParser;
	            Expression* expRet = nullptr;
	            expressionParser.parseExpression(lastTempVarDefaultValue, &expRet);
                stmtInput1.defaultValue = expRet;
            }
            stmt.inputs.push_back(stmtInput1);

            StmtBatchCalculation::StmtBatchCalculationInput stmtInput2;
            stmtInput2.name = getCGTActorExeTransSourceOutportVariableNameByName(inport->sourceOutport);
            stmtInput2.type = inport->type;
            stmtInput2.arraySize = inport->arraySize;
            stmt.inputs.push_back(stmtInput2);


            StmtBatchCalculation::StmtBatchCalculationOutput stmtOutput;
            if(mulCount + divCount == actorInfo->inports.size() - 1)
            {
                stmtOutput.name = actorInfo->name + "_" + outport->name;
                stmtOutput.type = outport->type;
                stmtOutput.arraySize = outport->arraySize;
            }
            else
            {
                lastTempVarName = actorInfo->name + "_" +  "BatchTempVar" + (actorInfo->inports.size() == 3 ? "" : to_string(mulCount + divCount));
                lastTempVarType = outport->type;
                lastTempVarArraySize = outport->arraySize;
                //if(stmtInput2.arraySize.size() > lastTempVarArraySize.size())
                //    lastTempVarArraySize = stmtInput2.arraySize;

                stmtOutput.name = lastTempVarName;
                stmtOutput.type = lastTempVarType;
                stmtOutput.arraySize = lastTempVarArraySize;
            }
            stmt.outputs.push_back(stmtOutput);

            ret.push_back(stmt);

            divCount++;
	    }
    }
    return ret;
}

vector<string> getMulOrDivSymbol(CGTActorExeTransActorInfo* actorInfo)
{
    vector<string> ret;
    string symbolStr = actorInfo->getParameterValueByName("Inputs");
    if(!symbolStr.empty() && symbolStr[0] >= '0' && symbolStr[0] <= '9')
    {
        for(int i = 0; i < actorInfo->inports.size(); i++)
        {
            ret.push_back("*");
        }
        return ret;
    }
    for(int i = 0; i < symbolStr.length(); i++)
    {
        if(symbolStr[i] == '*')
            ret.push_back("*");
        else if(symbolStr[i] == '/')
            ret.push_back("/");
    }
    if(ret.empty())
    {
        for(int i = 0; i < actorInfo->inports.size(); i++)
        {
            ret.push_back("*");
        }
    }
    return ret;
}