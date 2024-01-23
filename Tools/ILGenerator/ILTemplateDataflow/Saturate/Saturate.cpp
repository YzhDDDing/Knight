#pragma once
#include "../BasicTemplate.h"

// ��������˿ڵ�����Դ�����ƶϸ�������ж˿ڵ��������ͼ����鳤��

void transTypeInference()
{
    // ���� actorInfo.inports.source
    // ��� actorInfo.inports.type / arraySize
    // ��� actorInfo.outports.type / arraySize
    
    transTypeInferenceOutportSameAsInport();

}


// ����װ���ʽ��ʣ����������BasicTemplate�й���

string transInitExpression()
{
    return "";
}

// ����װ���ʽ��ʣ����������BasicTemplate�й���

string transExecExpression()
{
    if(actorInfo->outports.empty())
        return "";
    

    string upperLimit = actorInfo->getParameterValueByName("UpperLimit");
    if(upperLimit.empty())
        upperLimit = "0.5";
    string lowerLimit = actorInfo->getParameterValueByName("LowerLimit");
    if(lowerLimit.empty())
        lowerLimit = "-0.5";

    if(upperLimit == "inf" && lowerLimit == "-inf")
    {
        return "";
    }

    string expressionStr;
    string outVar = actorInfo->name + "_" + actorInfo->outports[0]->name;
	expressionStr += outVar + " = " + getCGTActorExeTransSourceOutportVariableNameByName(actorInfo->inports[0]->sourceOutport) + ";\n";
    
    if(upperLimit == "inf")
    {
        expressionStr += "if(" + outVar + " < " + lowerLimit + ")\n";
        expressionStr += outVar + " = " + lowerLimit + ";\n";
    }
    else if(lowerLimit == "-inf")
    {
        expressionStr += "if(" + outVar + " > " + upperLimit + ")\n";
        expressionStr += outVar + " = " + upperLimit + ";\n";
    }
    else
    {
        expressionStr += "if(" + outVar + " > " + upperLimit + ")\n";
        expressionStr += outVar + " = " + upperLimit + ";\n";
        expressionStr += "else if(" + outVar + " < " + lowerLimit + ")\n";
        expressionStr += outVar + " = " + lowerLimit + ";\n";
    }

    return expressionStr;
}

// ��������������IL����ֵ��ref

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
