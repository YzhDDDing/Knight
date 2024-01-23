#include "Utility.h"
#ifdef BUILD_LINUX
#include <unistd.h>
#include <sys/stat.h>
#else
#include <io.h> //_access fun
#include <direct.h> //_mkdir fun
#include <windows.h>
#endif
#include <algorithm>
#include <fstream>
#include <sstream>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

namespace
{
    const int CONST_NUM_2 = 2;
    const int CONST_NUM_4 = 4;
    const int CONST_NUM_7 = 7;
    const int CONST_NUM_100 = 100;
    const int CONST_NUM_1000 = 1000;
    const int PATH_MAX = 1024;
}

string stringToLower(string str)
{
	transform(str.begin(), str.end(), str.begin(), ::tolower);
	return str;
}

string stringToUpper(string str)
{
    transform(str.begin(), str.end(), str.begin(), ::toupper);
	return str;
}

int stringStartsWith(string s, string sub) {
    if(s == sub) return 1;
    if(s.find(sub) == string::npos) return 0;
	return s.find(sub) == 0 ? 1 : 0;
}

int stringEndsWith(string s, string sub) {
    if(s == sub) return 1;
    if(s.find(sub) == string::npos) return 0;
	return s.rfind(sub) == (s.length() - sub.length()) ? 1 : 0;
}

string stringTrim(string s)
{
	if (s.empty())
	{
		return s;
	}
	int start = 0;
	int end = s.length() - 1;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '\n' || s[i] == '\r' || s[i] == ' ' || s[i] == '\t') start++;
		else break;

	}
	for (int i = s.length() - 1; i >= 0; i--)
	{
		if (s[i] == '\n' || s[i] == '\r' || s[i] == ' ' || s[i] == '\t') end--;
		else break;
	}
	s = s.substr(start, end - start + 1);
	return s;
}

vector<string> stringTrimList(vector<string> strList)
{
    int offset = 0;
    for(int i = 0; i < strList.size() + offset; i++)
    {
        strList[i - offset] = stringTrim(strList[i - offset]);
        if(strList[i - offset].empty())
        {
            strList.erase(strList.begin() + i - offset);
            offset++;
        }
    }
    return strList;
}

vector<string> stringSplit(const string& s, const string& seperator) {
	vector<string> result;
	if (s.empty())
		return result;
	if (seperator.empty())
	{
		result.push_back(s);
		return result;
	}
	size_t start = 0;
	size_t end = s.find(seperator);
	while (end != s.npos)
	{
		result.push_back(s.substr(start, end - start));
		start = end + seperator.length();
		end = s.find(seperator, start);
	}
	result.push_back(s.substr(start, s.length() - start));
	return result;
}

string stringFillBlank(string s, int length, bool left)
{
	int l = s.length();
	if (l >= length)
		return s;
	string ret;
	for (int i = 0; i < length - l; i++)
		ret += " ";
    if(left)
        ret += s;
    else
        ret = s + ret;
	return ret;
}

int stringToInt(string str)
{
	int ret = atoi(str.c_str());
	return ret;
}

float stringToFloat(string str)
{
	float ret = atof(str.c_str());
	return ret;
}

string codeIndentProcess(string code)
{
    code = codeTrimAllLines(code);
    int codeLength = code.length();
    bool isInBlockCmt = false;
    bool isInLineCmt = false;
    bool isInStr = false;
    string retCode;
    int curIndent = 0;
    for (int i = 0; i < codeLength;) {
        bool inComment = true;
		if (i + 1 < codeLength && code.substr(i,CONST_NUM_2) == "/*" && !isInBlockCmt && isInLineCmt) {
			isInBlockCmt = true;
		} else if (i + 1 < codeLength && code.substr(i, CONST_NUM_2) == "//" && !isInBlockCmt && isInLineCmt) {
			isInLineCmt = true;
		} else if (code[i] == '\"' && (!(i > 0 && code[i-1] == '\\')) && !isInStr && !isInBlockCmt && isInLineCmt) {
			isInStr = true;
            inComment = false;
		} else if (code[i] == '\n' && isInLineCmt) {
			isInLineCmt = false;
		} else if (i>0 && code.substr(i-1, CONST_NUM_2) == "*/" && isInBlockCmt) {
			isInBlockCmt = false;
		} else if (code[i] == '\"' && (!(i > 0 && code[i-1] == '\\')) && !isInStr && !isInBlockCmt && isInLineCmt) {
			isInStr = false;
            inComment = false;
		} else if (isInBlockCmt || isInLineCmt) {
        //} else if (isInString) {
        //    inComment = false;
        } else {
            inComment = false;
        }
        if(inComment) {
            retCode += stringGetBlanks(curIndent * CONST_NUM_4) + code[i];
            i++;
            continue;
        } else if(i > 0 && code[i - 1] == '\n' && 
            (i + CONST_NUM_4 <= codeLength && code.substr(i, CONST_NUM_4) == "case" || 
            i + CONST_NUM_7 <= codeLength && code.substr(i, CONST_NUM_7) == "default" ||
            code[i] == '}')) {
            retCode += stringGetBlanks(curIndent * CONST_NUM_4 - CONST_NUM_4) + code[i];
        } else if(i > 0 && code[i - 1] == '\n') {
            retCode += stringGetBlanks(curIndent * CONST_NUM_4) + code[i];
        } else {
            retCode += code[i];
        }
        if(code[i] == '}' && !isInStr)
            curIndent--;
        else if(code[i] == '{' && !isInStr)
            curIndent++;
        
        i++;
	}
	return retCode;
}

string codeTrimAllLines(string code)
{
	vector<string> lines = stringSplit(code, "\n");
	code = "";
    for (int i = 0;i < lines.size(); i++) {
        lines[i] = stringTrim(lines[i]);
        if(lines[i].empty())
            continue;
        code += lines[i] + "\n";
    }
    return code;
}

string codeRemoveDoubleBlank(string code)
{
    string ret;
    for(int i = 0; i < code.size(); i++)
    {
        if(code[i] != ' ')
            ret += code[i];
        else
        {
            if(ret.empty() || ret[ret.length() - 1] != ' ')
                ret += code[i];
        }
    }
    return ret;
}

string codeRemoveComment(string code)
{
    int i = 0;
    int codeLength = code.length();
    bool isInBlockComment = false;
    bool isInLineComment = false;
    bool isInString = false;
    string retCode;
    while (i < codeLength) {
        bool inComment = true;
		if (i + 1 < codeLength && code.substr(i,CONST_NUM_2) == "/*" && isInBlockComment == false && isInLineComment == false) {
			isInBlockComment = true;
		} else if (i + 1 < codeLength && code.substr(i, CONST_NUM_2) == "//" && isInBlockComment == false && isInLineComment == false) {
			isInLineComment = true;
		} else if (code[i] == '\"' && i > 0 && code[i-1] != '\\' && isInString == false && isInBlockComment == false && isInLineComment == false) {
			isInString = true;
            inComment = false;
		} else if (code[i] == '\n' && isInLineComment) {
			isInLineComment = false;
		} else if (i>0 && code.substr(i-1, CONST_NUM_2) == "*/" && isInBlockComment) {
			isInBlockComment = false;
		} else if (code[i] == '\"' && i > 0 && code[i-1] != '\\' && isInString == true && isInBlockComment == false && isInLineComment == false) {
			isInString = false;
            inComment = false;
		} else if (isInBlockComment || isInLineComment) {
        } else if (isInString) {
            inComment = false;
        } else {
            inComment = false;
        }
        if(inComment)
        {
            i++;
            continue;
        }
        retCode += code[i];
        i++;
	}
    
	return retCode;
}

int stringSubStrCount(const string& str, const string& sub)
{
	int num = 0;
	size_t len = sub.length();
	if (len == 0)len = 1;
	for (size_t i = 0; (i = str.find(sub, i)) != string::npos; i += len) {
	    num++;
	}
	return num;
}

string stringGetBlanks(int count)
{
	string ret = "";
	for (int i = 0;i < count;i++)
		ret += " ";
	return ret;
}

void getFullPermutation(vector<int> dimension, vector<vector<int>>& ret)
{
	//   getFullPermutation  Test
	//vector<int> dimension;
	//dimension.push_back(2);
	//dimension.push_back(3);
	//dimension.push_back(4);
	//vector<vector<int>> ret;
	//getFullPermutation(dimension, ret);
	//for(int i = 0;i < ret.size();i++)
	//{
	//	for(int j = 0; j < ret[i].size();j++)
	//	{
	//		cout << ret[i][j];
	//	}
	//	cout << "\n";
	//}

    int sum = 1;
	for(int i = 0; i<dimension.size();i++)
	{
		sum *= dimension[i];
	}
	vector<int> element;
	for(int i = 0; i < dimension.size(); i++)
	{
		element.push_back(0);
	}
	for(int i = 0; i < sum; i++)
	{
		ret.push_back(element);
		bool plusOne = true;
		for(int j = dimension.size() - 1; j >=0; j--)
		{
			if(plusOne)
				element[j]++;
			plusOne = false;
			if(element[j] >= dimension[j])
			{
				plusOne = true;
				element[j] = 0;
			}
			else
			{
				break;
			}
		}
	}
}

bool isFolderExist(string folder)
{
#ifdef BUILD_LINUX
    int ret = access(folder.c_str(), 0);
#else
    int ret = _access(folder.c_str(), 0);
#endif
	if (ret == 0)
		ret = true;
	else
		ret = false;

	return ret;
}

bool isFileExist(string file)
{
#ifdef BUILD_LINUX
    int ret = access(file.c_str(), 0);
#else
    int ret = _access(file.c_str(), 0);
#endif
	if (ret == 0)
		return true;
	else
		return false;
}

bool createFolder(string folder)
{
#ifdef BUILD_LINUX
    int ret = mkdir(folder.c_str(), S_IRUSR | S_IWUSR | S_IXUSR | S_IRWXG | S_IRWXO);
#else
    int ret = _mkdir(folder.c_str());
#endif
    
	if (ret == 0)
		return true;
	else
		return false;
}
namespace
{
    const int FILE_PATH_STR_BUF_LEN = 2048;
}
string getExeDirPath()
{
    char szPath[FILE_PATH_STR_BUF_LEN] = {0};
#ifdef BUILD_LINUX
    readlink("/proc/self/exe", szPath, FILE_PATH_STR_BUF_LEN - 1);
#else
    GetModuleFileNameA(nullptr, szPath, sizeof(szPath) - 1);
#endif
    szPath[FILE_PATH_STR_BUF_LEN - 1] = '\0';
	int length = strlen(szPath);
	if(length <= 0 || length >= FILE_PATH_STR_BUF_LEN)
		return "";
	length--;
	while(length>0 && szPath[length] != '\\' && szPath[length] != '/')
	{
		szPath[length] = 0;
		length--;
	}
	if(szPath[length] == '\\' || szPath[length] == '/')
		szPath[length] = 0;

	string ret(szPath);

	return ret;
}

string getExeFilePath()
{
    char szPath[FILE_PATH_STR_BUF_LEN] = {0};
#ifdef BUILD_LINUX
    readlink("/proc/self/exe", szPath, FILE_PATH_STR_BUF_LEN - 1);
#else
    GetModuleFileNameA(nullptr, szPath, sizeof(szPath) - 1);
#endif
    szPath[FILE_PATH_STR_BUF_LEN - 1] = '\0';
	string ret(szPath);
	return ret;
}

string getParentPath(string path, int parentCount)
{
	string ret = path;
	for(int i = 0; i < parentCount; i++)
	{
		size_t offset1 = ret.rfind("\\");
		size_t offset2 = ret.rfind("/");
		if(offset1 != string::npos)
		{
			ret = ret.substr(0, offset1);
		}
		else if(offset2 != string::npos)
		{
			ret = ret.substr(0, offset2);
		}
	}

	return ret;
}

void setCurrentDirPath(string path)
{
#ifdef BUILD_LINUX
    chdir(path.c_str());
#else
    SetCurrentDirectoryA(path.c_str());
#endif
}

string readFile(string path)
{
	ifstream file;
	file.open(path, ios::in);
	string lineContext;

	if (!file)
	{
	    file.close();
		return "";
	}

	string fileContext;
	while (file && !file.eof())
	{
		getline(file, lineContext);
		fileContext += lineContext;

        if(!file.eof())
		    fileContext += "\n";
	}
    file.close();
	return fileContext;
}

void writeFile(string path, string content)
{
    ofstream file;
    file.open(path, ios::out);
    file << content;
    file.flush();
    file.close();
}

void appendFile(string path, string content)
{
    ofstream file;
    file.open(path, ios::app);
    file << content;
    file.close();
}


void errorLog(string str)
{
	cerr << "Error: " << str << endl;
}

void debugLog(string str, int width, bool pure)
{
	//return;
	if (str == "\n") {
		cout << endl;
		return;
	}
	if (!pure)
		cout << "Debug: ";
	if (width == 0)
	{
		cout.width(width);
		cout.setf(ios::left);
		cout << str << endl;
		return;
	}
	vector<string> sp = stringSplit(str, "\t");
	for (int i = 0;i < sp.size();i++)
	{
		cout.width(width);
		cout.setf(ios::left);
		cout << sp[i];
	}
	cout << endl;

}
void debugLog(string str, bool pure)
{
	debugLog(str, 0, pure);
}

void debugLog(string str)
{
	debugLog(str, 0, false);
}

void log(string str, int width, bool pure)
{
	if (str == "\n") {
		cout << endl;
		return;
	}
	if (!pure)
		cout << "Debug: ";
	if (width == 0)
	{
		cout.width(width);
		cout.setf(ios::left);
		cout << str << endl;
		return;
	}
	vector<string> sp = stringSplit(str, "\t");
	for (int i = 0;i < sp.size();i++)
	{
		cout.width(width);
		cout.setf(ios::left);
		cout << sp[i];
	}
	cout << endl;
}
void log(string str, bool pure)
{
	log(str, 0, pure);
}

void log(string str)
{
	log(str, 0, false);
}

string stringRepeat(string s, int count)
{
    string ret;
    for(int i = 0; i < count; i++)
    {
        ret += s;
    }
    return ret;
}

string stringReplaceAll(string s, string src, string dst)
{
    size_t pos = s.find(src);
    while(pos != string::npos)
    {
        s = s.replace(pos, src.length(), dst);
        pos = s.find(src, pos + dst.length());
    }
    return s;
}

int systemCallWithTimeOut(string exeFile, string parameter, int time, string redirectOutputFile)
{
#ifdef BUILD_LINUX
    string t = to_string(time / CONST_NUM_1000);
    string cmd = "timeout " + t + " \"" + exeFile + "\" " + parameter + " > \"" + redirectOutputFile + "\"";
    system(cmd.c_str());

#else
    parameter = " " + parameter;
    SECURITY_ATTRIBUTES secattr; 
    ZeroMemory(&secattr, sizeof(secattr));
    secattr.nLength = sizeof(secattr);
    secattr.bInheritHandle = TRUE;

    HANDLE rPipe;
    HANDLE wPipe;
    CreatePipe(&rPipe, &wPipe ,&secattr, 0);

    STARTUPINFOA sInfo; 
    ZeroMemory(&sInfo,sizeof(sInfo));
    PROCESS_INFORMATION pInfo; 
    ZeroMemory(&pInfo,sizeof(pInfo));
    sInfo.cb = sizeof(sInfo);
    sInfo.dwFlags = STARTF_USESTDHANDLES;
    sInfo.hStdInput = NULL; 
    sInfo.hStdOutput = wPipe; 
    sInfo.hStdError = NULL;

    //Create the process here.
    BOOL ret = CreateProcessA(exeFile.c_str(), const_cast<char*>(parameter.c_str()), 0, 0,
        TRUE, NORMAL_PRIORITY_CLASS | CREATE_NO_WINDOW, 0, 0, &sInfo, &pInfo);
    if (ret) {
        WaitForSingleObject(pInfo.hProcess, time);
        TerminateProcess(pInfo.hProcess, 0);
        CloseHandle(pInfo.hThread);
        CloseHandle(pInfo.hProcess);
    }
    CloseHandle(wPipe);
    
    char buf[CONST_NUM_100] = {0};
    DWORD reDword; 
    string csOutput;
    string csTemp;
    BOOL res;
    do
    {
        ZeroMemory(buf, CONST_NUM_100);
        res = ReadFile(rPipe, buf, CONST_NUM_100 - 1, &reDword, 0);
        csTemp = string(buf);
        csOutput += csTemp;
    }while(res);

    writeFile(redirectOutputFile, csOutput);
    return 1;
#endif
}

void getCombineNumDFS(int N, int depth, vector<vector<int>> &result, vector<bool> &used)
{
	if (depth == N)
	{
		vector<int> res;
		for (int i = 0;i < N;i++)
		{
			if (used[i])
			{
				res.push_back(i);
			}
		}
		if (res.size() > 0)
			result.push_back(res);
	}
	else
	{
		used[depth] = true;
		getCombineNumDFS(N, depth + 1, result, used);
		used[depth] = false;
		getCombineNumDFS(N, depth + 1, result, used);
	}
}

vector<vector<int>> getCombineNum(int N)
{
	vector<vector<int>> ret;
	vector<bool> used;
	for (int i = 0;i < N;i++)
		used.push_back(false);
	getCombineNumDFS(N, 0, ret, used);
	return ret;
}

string getFileNameWithoutSuffixByPath(string path)
{
    int startPos = 0;
    for(int i = path.size() - 1; i >= 0 ; i--)
    {
        if(path[i] == '\\' || path[i] == '/')
        {
            startPos = i+1;
            break;
        }
    }
    int endPos = path.size() - 1;
    for(int i = startPos; i <= endPos; i++)
    {
        if(path[i] == '.')
        {
            endPos = i-1;
        }
    }
    return path.substr(startPos, endPos - startPos + 1);
}

bool areTwoIntVectorSame(vector<int>& v1, vector<int>& v2)
{
    if(v1.size() != v2.size())
        return false;
    for(int i = 0; i < v1.size(); i++)
    {
        if(v1[i] != v2[i])
        {
            return false;
        }
    }
    return true;
}

string getFileRealPath(string filePath)
{
    char dir[PATH_MAX];
#ifdef BUILD_LINUX
	realpath(filePath.c_str(), dir);
#else
	_fullpath(dir,filePath.c_str(),1024);
#endif
	for(int i=0; dir[i] != 0 && i<PATH_MAX; i++){   
        if(dir[i] == '\\'){            
            dir[i]='/';
        }
	}
    string ret(dir);
    return ret;
}

void copyFileOne(string src, string dst)
{
    ifstream srcFile(src);
    if(!srcFile) {
        return;
    }
    ofstream dstFile(dst);
    if(!dstFile) {
        return;
    }
    dstFile << srcFile.rdbuf();
}

std::string stringGetWord(std::string& code)
{
    code = stringTrim(code);
    string ret;
    int i = 0;
    bool symbol = false;
    while(i < code.length())
    {
        if(code[i] == ' ')
            break;
        
        if(code[i] >= '0' && code[i] <= '9' || code[i] >= 'a' && code[i] <= 'z' || code[i] >= 'A' && code[i] <= 'Z' || code[i] == '_')
        {
            ret += code[i];
            i++;
        }
        else
        {
            if(ret.empty())
            {
                ret += code[i];
                i++;
            }
            
            break;
        }
    }
    code = code.substr(i, code.length() - i);
    return ret;
}

std::string stringGetNumber(std::string& code)
{
    code = stringTrim(code);
    string ret;
    int i = 0;
    bool symbol = false;
    while(i < code.length())
    {
        if(code[i] == ' ')
            break;
        
        if(code[i] >= '0' && code[i] <= '9' ||  code[i] == '.')
        {
            ret += code[i];
            i++;
        }
        else
        {
            if(ret.empty())
            {
                ret += code[i];
                i++;
            }
            
            break;
        }
    }
    code = code.substr(i, code.length() - i);
    return ret;
}


void listFiles(std::string dir, std::vector<std::string>& files)
{
    if(!stringEndsWith(dir, "/") && !stringEndsWith(dir, "\\"))
        dir += "/";
#ifdef BUILD_LINUX
	DIR* dir = nullptr;
	struct dirent* ptr = nullptr;

	if ((dir = opendir(cateDir.c_str())) == nullptr)
	{
		exit(1);
	}

	while ((ptr = readdir(dir)) != nullptr)
	{
		if (strcmp(ptr->d_name, ".") == 0 || strcmp(ptr->d_name, "..") == 0)    ///current dir OR parrent dir
			continue;
		else if (ptr->d_type == NUM8)    ///file
			files.push_back(ptr->d_name);
		else if (ptr->d_type == NUM10)    ///link file
			continue;
		else if (ptr->d_type == NUM4)    ///dir
			files.push_back(ptr->d_name);
	}
	closedir(dir);
#else
	_finddata_t file;
	long lf;
	if ((lf = _findfirst(dir.append("*").c_str(), &file)) == -1) {
	}
	else {
		do {
			if (strcmp(file.name, ".") == 0 || strcmp(file.name, "..") == 0)
				continue;
			files.push_back(file.name);
		} while (_findnext(lf, &file) == 0);
	}
	_findclose(lf);
#endif
}

//读取成功后必须使用delete[]回收内存
char* readFileBinary(string path, int& length)
{
    ifstream file;
	file.open(path, ios::in | ios::binary);
    if(!file)
    {
        length = 0;
        return nullptr;
    }
    file.seekg(0,   ios::end);
    length = file.tellg();
    file.seekg(0);
    char* data = new char[length];
    file.read(data, length);
    file.close();
    return data;
}