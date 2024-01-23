#include "LibFuzzerUtility.h"
#include <string.h>

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