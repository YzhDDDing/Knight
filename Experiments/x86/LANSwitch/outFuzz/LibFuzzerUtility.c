#include "LibFuzzerUtility.h"
#include "define.h"
#include <string.h>
#include <stdio.h>
#include <time.h>
const unsigned char* BranchCoverageData = NULL;
int BranchCoverageSize = 0;
long long LibFuzzerRunRounds = 0;
int TestCaseGenCount = 0;

int CoverageCount = 0;
int CoverageCountLast = 0;

void BranchCoverageRegister(const unsigned char* data, int size)
{
    LibFuzzerRunRounds++;
    BranchCoverageData = data;
    BranchCoverageSize = size;
    if(!BranchCoverageStartTime)
    {
        BranchCoverageStartTime = clock();
    }
}

void BranchCoverageStatistics(int branchId)
{
    if(BranchCoverageLibFuzzer[branchId])
        return;
    BranchCoverageLibFuzzer[branchId] = 1;
    CoverageCount++;
}

void BranchCoverageRecordTestCase()
{
    if(CoverageCountLast == CoverageCount)
        return;
    CoverageCountLast = CoverageCount;
    writeTestCaseBin();
    TestCaseGenCount++;
}

void writeStringNum(long long num, char* buf, int width)
{
    int c = 0;
    long long testCaseCountTemp = num;
    while(testCaseCountTemp){
        testCaseCountTemp /= 10;
        c++;
    }
    c = c == 0 ? 1 : c;
    int offset = 0;
    if(width > c) {
        offset = width - c;
    }
    for(int i = 0; i < offset; i++) {
        buf[i] = '0';
    }
    testCaseCountTemp = num;
    for(int i = 0; i < c; i++) {
        buf[offset+c-i-1] = '0' + testCaseCountTemp%10;
        testCaseCountTemp /= 10;
    }
    buf[offset+c] = 0;
}

void writeTestCaseBin()
{
    static char fileNameBuf[64] = "Out/";
    int perfixLen = 4;
    
    long long BranchCoverageEndTime = clock();
    long long testCostTime = (BranchCoverageEndTime - BranchCoverageStartTime);
    
    writeStringNum(TestCaseGenCount, &fileNameBuf[perfixLen + 0], 5);
    fileNameBuf[perfixLen + 5] = '_';
    fileNameBuf[perfixLen + 6] = '(';
    writeStringNum(CoverageCount, &fileNameBuf[perfixLen + 7], 5);
    fileNameBuf[perfixLen + 12] = 'o';
    fileNameBuf[perfixLen + 13] = 'f';
    writeStringNum(BRANCH_COVERAGE_COUNT, &fileNameBuf[perfixLen + 14], 5);
    fileNameBuf[perfixLen + 19] = ')';
    fileNameBuf[perfixLen + 20] = '_';
    writeStringNum(testCostTime, &fileNameBuf[perfixLen + 21], 0);
    
    FILE* writeFile = fopen(fileNameBuf, "wb");
    fwrite(BranchCoverageData, BranchCoverageSize, 1, writeFile);
    fclose(writeFile);
}

bool DataMapping_i8(unsigned char* const dst, const unsigned char* const src, int size, int min, int max)
{
    if (size != 1)
        return false;
    else if (min < INT8_MIN_VALUE)
        return false;
    else if (max > INT8_MAX_VALUE)
        return false;
    unsigned char range = 0xFF;
    unsigned char src_data;
    memcpy(&src_data, src, size);
    char result = ((float)src_data / range) * (max - min) + min;
    memcpy(dst, &result, size);
    return true;
}

bool DataMapping_i16(unsigned char* const dst, const unsigned char* const src, int size, int min, int max)
{
    if (size != 2)
        return false;
    else if (min < INT16_MIN_VALUE)
        return false;
    else if (max > INT16_MAX_VALUE)
        return false;
    unsigned short range = 0xFFFF;
    unsigned short src_data;
    memcpy(&src_data, src, size);
    short result = ((float)src_data / range) * (max - min) + min;
    memcpy(dst, &result, size);
    return true;
}

bool DataMapping_i32(unsigned char* const dst, const unsigned char* const src, int size, int min, int max)
{
    if (size != 4)
        return false;
    unsigned int range = 0xFFFFFFFF;
    unsigned int src_data;
    memcpy(&src_data, src, size);
    int result = ((float)src_data / range) * (max - min) + min;
    memcpy(dst, &result, size);
    return true;
}

bool DataMapping_i64(unsigned char* const dst, const unsigned char* const src, int size, long long min, long long max)
{
    if (size != 8)
        return false;
    unsigned long long range = 0xFFFFFFFFFFFFFFFF;
    unsigned long long src_data;
    memcpy(&src_data, src, size);
    long long result = ((double)src_data / range) * (max - min) + min;
    memcpy(dst, &result, size);
    return true;
}

bool DataMapping_u8(unsigned char* const dst, const unsigned char* const src, int size, unsigned int min, unsigned int max)

{
    if (size != 1)
        return false;
    else if (min > UINT8_MAX_VALUE)
        return false;
    else if (max > UINT8_MAX_VALUE)
        return false;
    unsigned char range = 0xFF;
    unsigned char src_data;
    memcpy(&src_data, src, size);
    unsigned char result = ((float)src_data / range) * (max - min) + min;
    memcpy(dst, &result, size);
    return true;
}

bool DataMapping_u16(unsigned char* const dst, const unsigned char* const src, int size, unsigned int min, unsigned int max)
{
    if (size != 2)
        return false;
    else if (min > UINT16_MAX_VALUE)
        return false;
    else if (max > UINT16_MAX_VALUE)
        return false;
    unsigned short range = 0xFFFF;
    unsigned short src_data;
    memcpy(&src_data, src, size);
    unsigned short result = ((float)src_data / range) * (max - min) + min;
    memcpy(dst, &result, size);
    return true;
}


bool DataMapping_u32(unsigned char* const dst, const unsigned char* const src, int size, unsigned int min, unsigned int max)
{
    if (size != 4)
        return false;
    unsigned int range = 0xFFFFFFFF;
    unsigned int src_data;
    memcpy(&src_data, src, size);
    unsigned int result = ((float)src_data / range) * (max - min) + min;
    memcpy(dst, &result, size);
    return true;
}

bool DataMapping_u64(unsigned char* const dst, const unsigned char* const src, int size, unsigned long long min, unsigned long long max)
{
    if (size != 8)
        return false;
    unsigned long long range = 0xFFFFFFFFFFFFFFFF;
    unsigned long long src_data;
    memcpy(&src_data, src, size);
    unsigned long long result = ((double)src_data / range) * (max - min) + min;
    memcpy(dst, &result, size);
    return true;
}

bool DataMapping_f32(unsigned char* const dst, const unsigned char* const src, int size, float min, float max)
{
    if (size != 4)
        return false;
    if (min == FLT_MIN_VALUE&& max == FLT_MAX_VALUE)
    {
        memcpy(dst, src, size);
    }
    else if (min == FLT_MIN_VALUE)
    {
        // 符号位变为1
        memcpy(dst, src, size);
        unsigned char* flag = dst + 3;
        *flag |= 0x80;
        float* dst_data = (float*)dst;
        *dst_data += max;
    }
    else if (max == FLT_MAX_VALUE)
    {
        // 符号位变为0
        memcpy(dst, src, size);
        unsigned char* flag = dst + 3;
        *flag &= 0x7F;
        float* dst_data = (float*)dst;
        *dst_data += min;
    }
    else {
        unsigned int range = 0xFFFFFFFF;
        unsigned int src_data;
        memcpy(&src_data, src, size);
        float result = ((float)src_data / range) * (max - min) + min;
        memcpy(dst, &result, size);
    }
    return true;
}

bool DataMapping_f64(unsigned char* const dst, const unsigned char* const src, int size, double min, double max)
{
    if (size != 8)
        return false;
    if (min == DBL_MIN_VALUE&& max == DBL_MAX_VALUE)
    {
        memcpy(dst, src, size);
    }
    else if (min == DBL_MIN_VALUE)
    {
        // 符号位变为1
        memcpy(dst, src, size);
        unsigned char* flag = dst + 7;
        *flag |= 0x80;
        double* dst_data = (double*)dst;
        *dst_data += max;
    }
    else if (max == DBL_MAX_VALUE)
    {
        // 符号位变为0
        memcpy(dst, src, size);
        unsigned char* flag = dst + 7;
        *flag &= 0x7F;
        double* dst_data = (double*)dst;
        *dst_data += min;
    }
    else {
        unsigned long long range = 0xFFFFFFFFFFFFFFFF;
        unsigned long long src_data;
        memcpy(&src_data, src, size);
        double result = ((double)src_data / range) * (max - min) + min;
        memcpy(dst, &result, size);
    }
    return true;
}