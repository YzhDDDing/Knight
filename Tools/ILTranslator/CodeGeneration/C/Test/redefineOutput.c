#include "redefineOutput.h"

char redefineOutputBuffer[65536];
int refputchar(char c){
    return c;
}
int refputc(char c, FILE* stream){
    return c;
}
int refputs(char* str, FILE* stream){
    return strlen(str);
}
int reputc(char c, FILE *stream){
    return c;
}
int reputchar(char c){
    return c;
}
int reputs(char* str){
    return strlen(str);
}
int revfprintf(FILE* stream, const char* format, ...){
	reva_list arglist;//定义va_list参数指针
	reva_start(arglist, format);//获取参数栈顶指针
	return vsprintf(redefineOutputBuffer, format, arglist);
}
int reprintf(const char* format, ...){
	reva_list arglist;//定义va_list参数指针
	reva_start(arglist, format);//获取参数栈顶指针
	return vsprintf(redefineOutputBuffer, format, arglist);
}
int refprintf(FILE* stream, const char* format, ...){
	reva_list arglist;
	reva_start(arglist, format);
	return vsprintf(redefineOutputBuffer, format, arglist);
}
FILE* refopen(const char *filename, const char *mode){
    return 1;
}
int refclose(FILE *fp){
    return 0;
}