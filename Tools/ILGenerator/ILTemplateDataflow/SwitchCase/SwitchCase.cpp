#pragma once
#include "../BasicTemplate.h"


// ��������˿ڵ�����Դ�����ƶϸ�������ж˿ڵ��������ͼ����鳤��



void transTypeInference()
{
    // ���� actorInfo.inports.source
    // ��� actorInfo.inports.type / arraySize
    // ��� actorInfo.outports.type / arraySize
    
    for(int i = 0; i < actorInfo->outports.size(); i++)
    {
        CGTActorExeTransOutport* outport = actorInfo->outports[i];
        outport->type = "bool";
        outport->arraySize.clear();
    }

}


// ����װ���ʽ��ʣ����������BasicTemplate�й���

string transInitExpression()
{
    return "";
}

// ����װ���ʽ��ʣ����������BasicTemplate�й���

string transExecExpression()
{
    string para = actorInfo->getParameterValueByName("CaseConditions");
    para = para.substr(1, para.length() - 2);
    vector<string> paras = stringSplit(para, ",");

    string code;

    CGTActorExeTransInport* inport = actorInfo->inports[0];

    for(int i = 0; i < actorInfo->outports.size(); i++)
    {
        CGTActorExeTransOutport* outport = actorInfo->outports[i];

        code += actorInfo->name + "_" + outport->name + " = ";

        string inportName = getCGTActorExeTransSourceOutportVariableNameByName(inport->sourceOutport);

        if(i != actorInfo->outports.size() - 1)
        {
            code += inportName + " == " + paras[i] + ";\n";
        }
        else
        {
            for (int j = 0; j < actorInfo->outports.size() - 1; j++)
            {
                CGTActorExeTransOutport* outportTemp = actorInfo->outports[j];
                code += "!" + actorInfo->name + "_" + outportTemp->name;
                if(j != actorInfo->outports.size() - 2)
                {
                    code += " && ";
                }
            }
            code += ";\n";
        }
    }

    return code;
}

// ��������������IL����ֵ��ref

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

vector<StmtBatchCalculation> transExecBatchCalculation()
{
    vector<StmtBatchCalculation> ret;
    return ret;
}