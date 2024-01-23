#pragma once
#include <string>
#include <map>


class ArgumentParser
{
public:

	void setHelpStr(std::string helpStr);
	void setDefaultValue(std::string flag, std::string value);
	int parseArguments(int argc, char** argv);
	
	bool hasFlagValue(std::string flag);
	std::string getFlagValue(std::string flag);

private:
	std::map<std::string, std::string> arguments;
	std::map<std::string, std::string> argumentsDefault;

	std::string helpStr;
};
