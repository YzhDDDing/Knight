#pragma once
#include "../BasicTemplate.h"

vector<string> getAddOrSubSymbol(CGTActorExeTransActorInfo* actorInfo);

// 根据输入端口的数据源类型推断该组件所有端口的数据类型及数组长度

void transTypeInference()
{
    CGTActorExeTransActorInfo* actorInfo = actorExeTransParser.transRoot->actorInfo;
    // 输入 ActorInfo.inports.source
    ILCalculate *retCalculateExec = &calculateExec;
    // 输出 retCalculateExec.inports.type / arraySize
    // 输出 retCalculateExec.outports.type / arraySize

    transTypeInferenceBasic(Token::Add);
    if(actorInfo->inports.size() == 1 && !actorInfo->inports[0]->arraySize.empty()){
        CGTActorExeTransOutport* outport = actorInfo->outports[0];
        outport->arraySize.clear();
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
    if(actorInfo->outports.empty())
        return "";


    // 单个端口为数组输入的情况
    string expressionStr;
    if(actorInfo->inports.size() == 1 && !actorInfo->inports[0]->arraySize.empty()){
        CGTActorExeTransOutport* outport = actorInfo->outports[0];
        CGTActorExeTransInport* inport = actorInfo->inports[0];
        int elementSize = 1;
        for(int i = 0; i < inport->arraySize.size(); i++)
        {
            elementSize *= inport->arraySize[i];
        }
        expressionStr += actorInfo->name + "_" + outport->name + " = 0;\n";
        expressionStr += "int " + actorInfo->name + "_i;\n";
        expressionStr += "for(" + actorInfo->name + "_i = 0; ";
        expressionStr += actorInfo->name + "_i <" + to_string(elementSize) + "; ";
        expressionStr += actorInfo->name + "_i ++){\n";
        expressionStr += actorInfo->name + "_" + outport->name + " += ";
        expressionStr += getCGTActorExeTransSourceOutportVariableNameByName(inport->sourceOutport);
        expressionStr += "[" + actorInfo->name + "_i];\n";
        expressionStr += "}\n";

        return expressionStr;
    }


    // 多个端口的情况
    vector<string> symbols = getAddOrSubSymbol(actorInfo);
    if(actorInfo->getParameterValueByName("SaturateOnIntegerOverflow") != "on")
    {
        expressionStr += actorInfo->name + "_" + actorInfo->outports[0]->name + " = ";
	    for (int i = 0; i < actorInfo->inports.size(); i++) {
            auto inport = actorInfo->inports[i];
		    if(i != 0 || symbols[i] != "+")
                expressionStr += " " + symbols[i] + " ";
            expressionStr += getCGTActorExeTransSourceOutportVariableNameByName(inport->sourceOutport);
	    }
        if(actorInfo->inports.empty()) {
            expressionStr += "0;";
        } else {
            expressionStr += ";";
        }
    }
    else
    {
        for (int i = 1; i < actorInfo->inports.size(); i++) {
            

            if(symbols[i] == "+")
            {
                expressionStr += "saturationAdd_" + actorInfo->outports[0]->type + "(";
            }
            else
            {
                expressionStr += "saturationSub_" + actorInfo->outports[0]->type + "(";
            }

            if(i == 1)
            {
                auto in1 = actorInfo->inports[i-1];
                auto in2 = actorInfo->inports[i];
                if(symbols[0] == "-") {
                    expressionStr += "-" + getCGTActorExeTransSourceOutportVariableNameByName(in1->sourceOutport) + ", ";
                } else {
                    expressionStr += getCGTActorExeTransSourceOutportVariableNameByName(in1->sourceOutport) + ", ";
                }
                expressionStr += getCGTActorExeTransSourceOutportVariableNameByName(in2->sourceOutport) + ", ";
                if(actorInfo->inports.size() == 2) {
                   expressionStr += "&" + actorInfo->name + "_" + actorInfo->outports[0]->name + ");";
                } else {
                    expressionStr += "&" + actorInfo->name + "_" + actorInfo->outports[0]->name + "_Sat" + to_string(i) + ");";
                }
            }
            else
            {
                auto in = actorInfo->inports[i];
                expressionStr += actorInfo->name + "_" + actorInfo->outports[0]->name + "_Sat" + to_string(i) + ", ";
                expressionStr += getCGTActorExeTransSourceOutportVariableNameByName(in->sourceOutport) + ", ";
                if(i == actorInfo->inports.size() - 1) {
                    expressionStr += "&" + actorInfo->name + "_" + actorInfo->outports[0]->name + ");";
                } else {
                    expressionStr += "&" + actorInfo->name + "_" + actorInfo->outports[0]->name + "_Sat" + to_string(i) + ");";
                }
            }

        }
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

    if(actorInfo->getParameterValueByName("SaturateOnIntegerOverflow") == "on")
    {
        ILUtilityFunction temp;
        temp.name = "saturationAdd_" + actorInfo->outports[0]->type;
        ret.push_back(temp);
    }
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

    ILLocalVariable temp;
    temp.name = actorInfo->name + "_" + actorInfo->outports[0]->name;
    temp.type = actorInfo->outports[0]->type;
    temp.arraySize = actorInfo->outports[0]->arraySize;

    ret.push_back(temp);

    if(actorInfo->getParameterValueByName("SaturateOnIntegerOverflow") == "on")
    {
        for(int i = 2; i < actorInfo->inports.size(); i++)
        {
            ILLocalVariable tempSatVar;
            tempSatVar.name = actorInfo->name + "_" + actorInfo->outports[0]->name + "_Sat" + to_string(i-1);
            tempSatVar.type = actorInfo->outports[0]->type;
            tempSatVar.arraySize = actorInfo->outports[0]->arraySize;

            ret.push_back(tempSatVar);
        }
    }


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
    if(actorInfo->inports.size() == 1 && !actorInfo->inports[0]->arraySize.empty())
        return ret;

    CGTActorExeTransOutport* outport = actorInfo->outports[0];
    string lastTempVarName = getCGTActorExeTransSourceOutportVariableNameByName(actorInfo->inports[0]->sourceOutport);
    string lastTempVarType = actorInfo->inports[0]->type;
    vector<int> lastTempVarArraySize = actorInfo->inports[0]->arraySize;
    string lastTempVarDefaultValue;
    
    vector<string> symbols = getAddOrSubSymbol(actorInfo);
    int addCount = 0;
	for (int i = 0; i < actorInfo->inports.size(); i++) {
        auto inport = actorInfo->inports[i];
		if(symbols[i] != "+")
            continue;
        if(addCount == 0)
        {
            lastTempVarName = getCGTActorExeTransSourceOutportVariableNameByName(inport->sourceOutport);
            lastTempVarType = inport->type;
            lastTempVarArraySize = inport->arraySize;
        }
        else
        {
            StmtBatchCalculation stmt;
            stmt.operationType = StmtBatchCalculation::TypeAdd;
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
                lastTempVarName = actorInfo->name + "_" +  "BatchTempVar" + (actorInfo->inports.size() == 3 ? "" : to_string(addCount));
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
        addCount++;
	}
    if(addCount == 0 && symbols.size() > 0)
    {
        lastTempVarName = "";
        lastTempVarType = outport->type;
        lastTempVarArraySize.clear();
        lastTempVarDefaultValue = "0";
    }
    int subCount = 0;
    if(addCount < symbols.size())
    {
        for (int i = 0; i < actorInfo->inports.size(); i++) {
            auto inport = actorInfo->inports[i];
		    if(symbols[i] != "-")
                continue;

            StmtBatchCalculation stmt;
            stmt.operationType = StmtBatchCalculation::TypeSub;
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
            if(addCount + subCount == actorInfo->inports.size() - 1)
            {
                stmtOutput.name = actorInfo->name + "_" + outport->name;
                stmtOutput.type = outport->type;
                stmtOutput.arraySize = outport->arraySize;
            }
            else
            {
                lastTempVarName = actorInfo->name + "_" +  "BatchTempVar" + (actorInfo->inports.size() == 3 ? "" : to_string(addCount + subCount));
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

            subCount++;
	    }
    }

    return ret;
}

vector<string> getAddOrSubSymbol(CGTActorExeTransActorInfo* actorInfo)
{
    vector<string> ret;
    string symbolStr = actorInfo->getParameterValueByName("Inputs");
    for(int i = 0; i < symbolStr.length(); i++)
    {
        if(symbolStr[i] == '+')
            ret.push_back("+");
        else if(symbolStr[i] == '-')
            ret.push_back("-");
    }
    if(ret.empty())
    {
        for(int i = 0; i < actorInfo->inports.size(); i++)
        {
            ret.push_back("+");
        }
    }
    return ret;
}