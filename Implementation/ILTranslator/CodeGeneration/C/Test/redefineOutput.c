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
	reva_list arglist;//����va_list����ָ��
	reva_start(arglist, format);//��ȡ����ջ��ָ��
	return vsprintf(redefineOutputBuffer, format, arglist);
}
int reprintf(const char* format, ...){
	reva_list arglist;//����va_list����ָ��
	reva_start(arglist, format);//��ȡ����ջ��ָ��
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