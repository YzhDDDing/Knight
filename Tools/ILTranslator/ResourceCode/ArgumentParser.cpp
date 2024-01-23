#include "ArgumentParser.h"
#include "Utility.h"
using namespace std;

void ArgumentParser::setHelpStr(string helpStr)
{
	this->helpStr = "Help Information:\n" + helpStr;
}

void ArgumentParser::setDefaultValue(string flag, string value)
{
	argumentsDefault[flag] = value;
}

int ArgumentParser::parseArguments(int argc, char** argv)
{
	string curFlag;
	for(int i = 1; i < argc; i++)
	{
		string argStr(argv[i]);
		if(stringStartsWith(argStr, "-"))
		{
			if(!curFlag.empty())
			{
				arguments[curFlag] = "";
			}
			curFlag = argStr;
		}
		else if(!curFlag.empty())
		{
			arguments[curFlag] = argStr;
			curFlag.clear();
		}
        
		if((curFlag == "-help" || curFlag == "-h") && 
			!this->helpStr.empty())
		{
			cout << this->helpStr << endl;
			return 0;
		}
	}
	return 1;
}

bool ArgumentParser::hasFlagValue(string flag)
{
	if(arguments.find(flag) == arguments.end())
		return argumentsDefault.find(flag) == argumentsDefault.end();
	return true;
}

string ArgumentParser::getFlagValue(string flag)
{
	if(arguments.find(flag) == arguments.end())
	{
	    if(argumentsDefault.find(flag) == argumentsDefault.end())
	    {
	        return "";
	    }
        return argumentsDefault[flag];
	}
	return arguments[flag];
}
