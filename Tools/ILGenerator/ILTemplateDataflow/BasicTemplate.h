#pragma once

#include <string>

#include "../../../Src/Common/Utility.h"
#include "../../../Src/ILBasic/BasicTypeCalculator.h"
#include "../../../Src/ILBasic/Expression.h"
#include "../../../Src/ILBasic/ILCCodeParser.h"
#include "../../../Src/ILBasic/ILCalculate.h"
#include "../../../Src/ILBasic/ILEnumDefine.h"
#include "../../../Src/ILBasic/ILExpressionParser.h"
#include "../../../Src/ILBasic/ILGlobalVariable.h"
#include "../../../Src/ILBasic/ILHeadFile.h"
#include "../../../Src/ILBasic/ILInput.h"
#include "../../../Src/ILBasic/ILLocalVariable.h"
#include "../../../Src/ILBasic/ILMacro.h"
#include "../../../Src/ILBasic/ILMember.h"
#include "../../../Src/ILBasic/ILObject.h"
#include "../../../Src/ILBasic/ILOutput.h"
#include "../../../Src/ILBasic/ILRef.h"
#include "../../../Src/ILBasic/ILSaver.h"
#include "../../../Src/ILBasic/ILStructDefine.h"
#include "../../../Src/ILBasic/ILTypeDefine.h"
#include "../../../Src/ILBasic/ILUtilityFunction.h"
#include "../../../Src/ILBasic/StmtLocalVariable.h"
#include "../../../Src/ILBasic/StmtIf.h"
#include "../../../Src/ILBasic/StmtExpression.h"
#include "../../../Src/ILGenerator/CGTActorExeTransParser.h"

using namespace std;

#define DLL extern "C" __declspec(dllexport)

CGTActorExeTransParser actorExeTransParser;

vector<ILHeadFile> headFileList;
vector<ILMacro> macroList;
vector<ILTypeDefine> typeDefineList;
vector<ILEnumDefine> enumDefineList;
vector<ILStructDefine> structDefineList;
vector<ILUtilityFunction> utilityFunctionList;
vector<ILGlobalVariable> globalVariableList;
vector<ILLocalVariable> localVariableList;
ILCalculate calculateInit;
ILCalculate calculateExec;

CGTActorExeTransActorInfo* actorInfo;

// 组件模板函数
void transTypeInference();
vector<ILHeadFile> transHeadFile();
vector<ILMacro> transMacro();
vector<ILTypeDefine> transTypeDefine();
vector<ILEnumDefine> transEnumDefine();
vector<ILStructDefine> transStructDefine();
vector<ILUtilityFunction> transUtilityFunction();
vector<ILGlobalVariable> transGlobalVariable();
vector<ILLocalVariable> transLocalVariable();
string transExecExpression();
string transInitExpression();
vector<StmtBatchCalculation> transExecBatchCalculation();

void translateInputs(ILCalculate* calculate);
void translateOutputs(ILCalculate* calculate);
int parseInitExpression(string expressionStr, char* error, int errorLength);
int parseExecExpression(string expressionStr, char* error, int errorLength);
int parseExecBatchCalculation(vector<StmtBatchCalculation>& stmts, char* error,
	int errorLength);
void addRefToILObject();

int writeReturnXML(char* xmlBuffer, int xmlBufferLength, char* error,
	int errorLength);
// int trans(char* xmlBuffer, int xmlBufferLength, char* error, int
// errorLength);

string defaultType = "f32";

map<string, string> basicTypeNameMap = {
	pair<string, string>("uint8", "u8"),
	pair<string, string>("int8", "i8"),
	pair<string, string>("uint16", "u16"),
	pair<string, string>("int16", "i16"),
	pair<string, string>("uint32", "u32"),
	pair<string, string>("int32", "i32"),
	pair<string, string>("uint64", "u64"),
	pair<string, string>("int64", "i64"),
	pair<string, string>("single", "f32"),
	pair<string, string>("double", "f64"),
	pair<string, string>("float32", "f32"),
	pair<string, string>("float64", "f64"),
	pair<string, string>("boolean", "bool"),
};

map<string, string> basicCodeDataTypeMap = {
    pair<string, string>("i32", "int"),
    pair<string, string>("f32", "float"),
    pair<string, string>("i64", "long long"),
    pair<string, string>("f64", "double"),
    pair<string, string>("f128", "long double"),
    pair<string, string>("i8", "char"),
    pair<string, string>("i16", "short"),
    pair<string, string>("u32", "unsigned int"),
    pair<string, string>("u64", "unsigned long long"),
    pair<string, string>("u8", "unsigned char"),
    pair<string, string>("u16", "unsigned short"),
    pair<string, string>("short int", "short"),
    pair<string, string>("sint32", "int"),
};

void release() {
	for (int i = 0; i < headFileList.size(); i++) {
		headFileList[i].release();
	}
	headFileList.clear();
	for (int i = 0; i < macroList.size(); i++) {
		macroList[i].release();
	}
	macroList.clear();
	for (int i = 0; i < typeDefineList.size(); i++) {
		typeDefineList[i].release();
	}
	typeDefineList.clear();
	for (int i = 0; i < enumDefineList.size(); i++) {
		enumDefineList[i].release();
	}
	enumDefineList.clear();
	for (int i = 0; i < structDefineList.size(); i++) {
		structDefineList[i].release();
	}
	structDefineList.clear();
	for (int i = 0; i < utilityFunctionList.size(); i++) {
		utilityFunctionList[i].release();
	}
	utilityFunctionList.clear();
	for (int i = 0; i < headFileList.size(); i++) {
		headFileList[i].release();
	}
	headFileList.clear();
	for (int i = 0; i < globalVariableList.size(); i++) {
		globalVariableList[i].release();
	}
	globalVariableList.clear();
	for (int i = 0; i < localVariableList.size(); i++) {
		localVariableList[i].release();
	}
	localVariableList.clear();
	calculateInit.release();
	calculateExec.release();
	actorExeTransParser.release();
}

DLL int init(const char* xml, int xmlLength, char* error, int errorLength) {
	release();
	int res = actorExeTransParser.parseCGTActorExeTrans(xml, xmlLength);
	if (res < 0) {
		if (errorLength < actorExeTransParser.getErrorStr().size()) {
			char errorMessage[] = "Error memory is not enough.";
			strcpy_s(error, errorLength, errorMessage);
			return res;
		}
		strcpy_s(error, errorLength, actorExeTransParser.getErrorStr().c_str());
		return res;
	}
	actorInfo = actorExeTransParser.transRoot->actorInfo;
	return 1;
}

DLL int trans(char* xmlBuffer, int xmlBufferLength, char* error,
	int errorLength) {
	int res;
	calculateInit.name = actorExeTransParser.transRoot->actorInfo->name;

	calculateExec.name = actorExeTransParser.transRoot->actorInfo->name;

	transTypeInference();
	// 解析Inputs
	translateInputs(&calculateExec);
	// 解析Outputs
	translateOutputs(&calculateExec);

	string expressionStr = transInitExpression();
	if (!expressionStr.empty() &&
		(res = parseInitExpression(expressionStr, error, errorLength)) < 0) {
		return res;
	}

	vector<StmtBatchCalculation> stmtBatchCalculations =
		transExecBatchCalculation();
	if (stmtBatchCalculations.empty()) {
		expressionStr = transExecExpression();
		if (!expressionStr.empty() &&
			(res = parseExecExpression(expressionStr, error, errorLength)) < 0) {
			return res;
		}
	}
	else {
		if ((res = parseExecBatchCalculation(stmtBatchCalculations, error,
			errorLength)) < 0) {
			return res;
		}
	}

	headFileList = transHeadFile();
	macroList = transMacro();
	typeDefineList = transTypeDefine();
	enumDefineList = transEnumDefine();
	structDefineList = transStructDefine();
	utilityFunctionList = transUtilityFunction();
	globalVariableList = transGlobalVariable();
	localVariableList = transLocalVariable();

	addRefToILObject();

	if ((res = writeReturnXML(xmlBuffer, xmlBufferLength, error, errorLength)) <
		0) {
		return res;
	}

	return 1;
}

void basicTypeInference() {}

CGTActorExeTransSourceOutport*
getCGTActorExeTransSourceOutportByName(string name, int srcIndex = 0) {

    vector<string> nameSp = stringSplit(name, ",");
	for (int i = 0;
		i <
		actorExeTransParser.transRoot->sourceOutportInfo->sourceOutports.size();
		i++) {
		CGTActorExeTransSourceOutport* src =
			actorExeTransParser.transRoot->sourceOutportInfo->sourceOutports[i];
		if (nameSp[srcIndex] == src->actorName + "." + src->name ||
			(src->actorName.empty() && nameSp[srcIndex] == src->name)) {
			return src;
		}
	}
	return nullptr;
}

string getCGTActorExeTransSourceOutportVariableNameByName(string name, int srcIndex = 0) {
    vector<string> nameSp = stringSplit(name, ",");
	for (int i = 0;
		i <
		actorExeTransParser.transRoot->sourceOutportInfo->sourceOutports.size();
		i++) {
		CGTActorExeTransSourceOutport* src =
			actorExeTransParser.transRoot->sourceOutportInfo->sourceOutports[i];
		if (nameSp[srcIndex] == src->actorName + "." + src->name) {
			return src->actorName + "_" + src->name;
		}
		else if (src->actorName.empty() && nameSp[srcIndex] == src->name) {
			return src->name;
		}
	}
	return "";
}

string getCGTActorExeTransSourceOutportVariableNameByPort(
	CGTActorExeTransSourceOutport* const sourceOutport) {
	if (sourceOutport->actorName.empty())
		return sourceOutport->name;
	else
		return sourceOutport->actorName + "_" + sourceOutport->name;
}

void translateInputs(ILCalculate* calculate) {
	for (auto inport : actorExeTransParser.transRoot->actorInfo->inports) {
		// 目前先转换这几个属性 input不一定完整
		ILInput* input = new ILInput();
		input->name = inport->name;
		input->type = inport->type;
		input->arraySize = inport->arraySize;
		std::vector<std::string> strings = stringSplit(inport->sourceOutport, ".");
		std::string sourceStr;
		for (int i = 0; i < strings.size() - 1; i++) {
			sourceStr += strings[i] + "_";
		}
		sourceStr += strings[strings.size() - 1];
		input->sourceStr = sourceStr;
		calculate->inputs.push_back(input);
	}
}

void translateOutputs(ILCalculate* calculate) {
	for (auto outport : actorExeTransParser.transRoot->actorInfo->outports) {
		// 目前先转换这几个属性 output不一定完整
		ILOutput* output = new ILOutput();
		output->name = outport->name;
		output->type = outport->type;
		output->arraySize = outport->arraySize;
		calculate->outputs.push_back(output);
	}
}

void translateRefs(ILObject* object) {
	vector<ILRef*>* refList = object->getListOfILRef();
	if (!refList)
		return;

	ILRef* ref = new ILRef(object);
	ref->path = actorExeTransParser.transRoot->modelInfo->name + "." +
		actorExeTransParser.transRoot->functionInfo->name + "." +
		actorExeTransParser.transRoot->actorInfo->name;
	ref->actor = actorExeTransParser.transRoot->actorInfo->type;
	refList->push_back(ref);
}

int writeError(string errorStr, char* error, int errorLength, int retValue) {
	if (errorLength < errorStr.length()) {
		char errorMessage[] = "Error memory is not enough.";
		strcpy_s(error, errorLength, errorMessage);
		return retValue;
	}
	strcpy_s(error, errorLength, errorStr.c_str());
	return retValue;
}

int parseExecBatchCalculation(vector<StmtBatchCalculation>& stmts, char* error,
	int errorLength) {
	for (int i = 0; i < stmts.size(); i++) {
		StmtBatchCalculation* stmt = new StmtBatchCalculation();
		stmt->operationType = stmts[i].operationType;
		stmt->shapeType = stmts[i].shapeType;
		stmt->modifierType = stmts[i].modifierType;
		stmt->dataType = stmts[i].dataType;
		stmt->inputs = stmts[i].inputs;
		stmt->outputs = stmts[i].outputs;

		calculateExec.statements.childStatements.push_back(stmt);
	}
	return 1;
}

int parseExecExpression(string expressionStr, char* error, int errorLength) {
	ILCCodeParser codeParser;
	// parse C code
	int res = codeParser.parseCCode(expressionStr, &calculateExec.statements);
	if (res < 0) {
		return writeError(codeParser.getErrorStr(), error, errorLength, res);
	}
	return 1;
}

int parseInitExpression(string expressionStr, char* error, int errorLength) {
	ILCCodeParser codeParser;
	// parse C code
	int res = codeParser.parseCCode(expressionStr, &calculateInit.statements);
	if (res < 0) {
		return writeError(codeParser.getErrorStr(), error, errorLength, res);
	}
	return 1;
}

void addRefToILObject() {
	for (int i = 0; i < headFileList.size(); i++) {
		translateRefs(&headFileList[i]);
	}
	for (int i = 0; i < macroList.size(); i++) {
		translateRefs(&macroList[i]);
	}
	for (int i = 0; i < typeDefineList.size(); i++) {
		translateRefs(&typeDefineList[i]);
	}
	for (int i = 0; i < enumDefineList.size(); i++) {
		translateRefs(&enumDefineList[i]);
	}
	for (int i = 0; i < structDefineList.size(); i++) {
		translateRefs(&structDefineList[i]);
	}
	for (int i = 0; i < utilityFunctionList.size(); i++) {
		translateRefs(&utilityFunctionList[i]);
	}
	for (int i = 0; i < globalVariableList.size(); i++) {
		translateRefs(&globalVariableList[i]);
	}
	for (int i = 0; i < localVariableList.size(); i++) {
		translateRefs(&localVariableList[i]);
	}
	translateRefs(&calculateInit);
	translateRefs(&calculateExec);

	if (actorInfo->type == "Function") {
		string functionName = actorInfo->getParameterValueByName("FunctionRef");
		vector<ILRef*>* refList = calculateInit.getListOfILRef();
		if (refList) {
			ILRef* ref = new ILRef(&calculateInit);
			ref->path = functionName;
			ref->actor = "CompositeActor";
			refList->push_back(ref);
		}
		refList = calculateExec.getListOfILRef();
		if (refList) {
			ILRef* ref = new ILRef(&calculateExec);
			ref->path = functionName;
			ref->actor = "CompositeActor";
			refList->push_back(ref);
		}
	}
}

int writeReturnXML(char* xmlBuffer, int xmlBufferLength, char* error,
	int errorLength) {
	// save Calculate
	tinyxml2::XMLDocument doc;
	tinyxml2::XMLElement* root = doc.NewElement("Root");
	doc.InsertEndChild(root);

	ILSaver ilSaver;
	int res;

	for (int i = 0; i < headFileList.size(); i++) {
		if ((res = ilSaver.saveHeadFile(&headFileList[i], root, &doc)) < 0) {
			return writeError("Save head file error.", error, errorLength, res);
			;
		}
	}
	for (int i = 0; i < macroList.size(); i++) {
		if ((res = ilSaver.saveMacro(&macroList[i], root, &doc)) < 0) {
			return writeError("Save macro error.", error, errorLength, res);
			;
		}
	}
	for (int i = 0; i < typeDefineList.size(); i++) {
		if ((res = ilSaver.saveTypeDefine(&typeDefineList[i], root, &doc)) < 0) {
			return writeError("Save type define error.", error, errorLength, res);
			;
		}
	}
	for (int i = 0; i < enumDefineList.size(); i++) {
		if ((res = ilSaver.saveEnumDefine(&enumDefineList[i], root, &doc)) < 0) {
			return writeError("Save enum define error.", error, errorLength, res);
			;
		}
	}
	for (int i = 0; i < structDefineList.size(); i++) {
		if ((res = ilSaver.saveStructDefine(&structDefineList[i], root, &doc)) <
			0) {
			return writeError("Save struct define error.", error, errorLength, res);
			;
		}
	}
	for (int i = 0; i < utilityFunctionList.size(); i++) {
		if ((res = ilSaver.saveUtilityFunction(&utilityFunctionList[i], root,
			&doc)) < 0) {
			return writeError("Save utility function error.", error, errorLength,
				res);
			;
		}
	}
	for (int i = 0; i < globalVariableList.size(); i++) {
		if ((res = ilSaver.saveGlobalVariable(&globalVariableList[i], root, &doc)) <
			0) {
			return writeError("Save global variable error.", error, errorLength, res);
			;
		}
	}
	for (int i = 0; i < localVariableList.size(); i++) {
		if ((res = ilSaver.saveLocalVariable(&localVariableList[i], root, &doc)) <
			0) {
			return writeError("Save local variable error.", error, errorLength, res);
			;
		}
	}

	tinyxml2::XMLElement* initXMLNode = doc.NewElement("InitCalculate");
	root->InsertEndChild(initXMLNode);
	if ((res = ilSaver.saveCalculate(&calculateInit, initXMLNode, &doc)) < 0) {
		return writeError("Save init calculate error.", error, errorLength, res);
		;
	}

	tinyxml2::XMLElement* updateXMLNode = doc.NewElement("UpdateCalculate");
	root->InsertEndChild(updateXMLNode);
	if ((res = ilSaver.saveCalculate(&calculateExec, updateXMLNode, &doc)) < 0) {
		return writeError("Save update calculate error.", error, errorLength, res);
		;
	}

	tinyxml2::XMLPrinter* printer = new tinyxml2::XMLPrinter();
	doc.Print(printer);

	if (printer->CStrSize() > xmlBufferLength) {
		char errorMessage[] = "XML memory is not enough.";
		strcpy_s(error, errorLength, errorMessage);
		return -1;
	}
	else {
		strcpy_s(xmlBuffer, xmlBufferLength, printer->CStr());
	}
	return 1;
}

string getSimulinkOutDataType() {
	string oriType = "#Default";
	if (!actorInfo->outports.empty()) {
		oriType = actorInfo->outports[0]->type;
	}
	string outputTypeStr = actorInfo->getParameterValueByName("OutDataTypeStr");
	if (outputTypeStr.empty())
		return "#Default";

	if (actorInfo->outports.empty())
		return oriType;
	if (basicTypeNameMap.find(outputTypeStr) == basicTypeNameMap.end())
		return oriType;

	return basicTypeNameMap.at(outputTypeStr);
}

void transTypeInferenceBasic(Token::Type op) {
	string outType = "f32";
	vector<int> outArraySize;
	for (int i = 0; i < actorInfo->inports.size(); i++) {
		CGTActorExeTransInport* inport = actorInfo->inports[i];
		CGTActorExeTransSourceOutport* src =
			getCGTActorExeTransSourceOutportByName(inport->sourceOutport);
		if (inport->type == "#Default" ||
			(inport->type != src->type && src->type != "#Default")) {
			inport->type = src->type;
		}
		if (inport->arraySize.empty()) {
			inport->arraySize = src->arraySize;
		}
        if (i == 0 && inport->type != "#Default") {
			outType = inport->type;
		}
		else if (op != Token::Unknow) {
			outType = BasicTypeCalculator::getExpResultType(
				outType == "#Default" ? "f32" : outType,
				inport->type == "#Default" ? "f32" : inport->type, op);
		}
		if (inport->arraySize.size() > outArraySize.size()) {
			outArraySize = inport->arraySize;
		}
	}

	if (!actorInfo->outports.empty()) {
		CGTActorExeTransOutport* outport = actorInfo->outports[0];
		outport->type = getSimulinkOutDataType();
		if (outport->type == "#Default") {
			outport->type = outType;
		}
		outport->arraySize = outArraySize;
	}
}

void transTypeInferenceOutportSameAsInport(int sameAsInportIndex = 0) {
	string outType;
	vector<int> outArraySize;
	for (int i = 0; i < actorInfo->inports.size(); i++) {
		CGTActorExeTransInport* inport = actorInfo->inports[i];
		CGTActorExeTransSourceOutport* src =
			getCGTActorExeTransSourceOutportByName(inport->sourceOutport);
		if (inport->type == "#Default") {
			inport->type = src->type;
		}
		if (inport->arraySize.empty()) {
			inport->arraySize = src->arraySize;
		}
		string inputPortWidthStr =
			actorInfo->getParameterValueByName("InputPortWidth");
		if (!inputPortWidthStr.empty()) {
			inport->arraySize.clear();
			inport->arraySize.push_back(stringToInt(inputPortWidthStr));
		}

		if (i == sameAsInportIndex) {
			outType = inport->type;
			outArraySize = inport->arraySize;
		}
	}

	for (int i = 0; i < actorInfo->outports.size(); i++) {
		CGTActorExeTransOutport* outport = actorInfo->outports[i];
		outport->type = getSimulinkOutDataType();
		if (outport->type == "#Default") {
			outport->type = outType;
		}
		outport->arraySize = outArraySize;
		string outputSizesStr = actorInfo->getParameterValueByName("OutputSizes");
		if (!outputSizesStr.empty()) {
			outport->arraySize.clear();
			outport->arraySize.push_back(stringToInt(outputSizesStr));
		}
	}
}

void transTypeInferencePassInportFromSrc() {
	for (int i = 0; i < actorInfo->inports.size(); i++) {
		CGTActorExeTransInport* inport = actorInfo->inports[i];
		CGTActorExeTransSourceOutport* src =
			getCGTActorExeTransSourceOutportByName(inport->sourceOutport);
		if (inport->type == "#Default") {
			inport->type = src->type;
		}
		if (inport->arraySize.empty()) {
			inport->arraySize = src->arraySize;
		}
		string inputPortWidthStr =
			actorInfo->getParameterValueByName("InputPortWidth");
		if (!inputPortWidthStr.empty()) {
			inport->arraySize.clear();
			inport->arraySize.push_back(stringToInt(inputPortWidthStr));
		}
	}
}

vector<string> getIndexStrs(string indexStr) {
	int left = 0;
	int current = 0;
	int length = indexStr.length();
	vector<string> indexStrs;
	while (current < length) {
		if (indexStr[current] == '[') {
			while (current < length && indexStr[current++] != ']')
				;
			indexStrs.push_back(indexStr.substr(left, current - left));
			left = ++current;
		}
		else if (indexStr[current] == ',') {
			indexStrs.push_back(indexStr.substr(left, current - left));
			left = ++current;
		}
		else {
			current++;
		}
	}
	if (current > left) {
		indexStrs.push_back(indexStr.substr(left, current - left));
	}
	return indexStrs;
}


vector<int> parseUtilityArraySize(std::string str)
{
    vector<int> ret;
    if(str.empty())
        return ret;
    if(str[0] == '[')
        str = str.substr(1, str.length() - 2);
	vector<string> arraySizeStrSplit = stringSplit(str, ",");
	for(int i = 0;i < arraySizeStrSplit.size();i++)
	{
		ret.push_back(stringToInt(arraySizeStrSplit[i]));
	}
    return ret;
}

string getSimpleDataTypeFromSimulinkType(string dataTypeStr)
{
	if (basicTypeNameMap.find(dataTypeStr) != basicTypeNameMap.end())
		return basicTypeNameMap.at(dataTypeStr);
    return "unknown";
}

string getCodeDataTypeFromSimpleType(string dataTypeStr)
{
	if (basicCodeDataTypeMap.find(dataTypeStr) != basicCodeDataTypeMap.end())
		return basicCodeDataTypeMap.at(dataTypeStr);
    return "unknown";
}