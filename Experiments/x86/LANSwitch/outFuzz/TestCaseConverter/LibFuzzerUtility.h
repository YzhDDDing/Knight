#pragma once
#define INT8_MIN_VALUE        (-127 - 1)
#define INT16_MIN_VALUE       (-32767 - 1)
#define INT32_MIN_VALUE       (-2147483647 - 1)
#define INT64_MIN_VALUE       (-9223372036854775807 - 1)
#define INT8_MAX_VALUE         127
#define INT16_MAX_VALUE        32767
#define INT32_MAX_VALUE        2147483647
#define INT64_MAX_VALUE        9223372036854775807
#define UINT8_MAX_VALUE        0xffu
#define UINT16_MAX_VALUE       0xffff
#define UINT32_MAX_VALUE       0xffffffff
#define DBL_MAX_VALUE          1.7976931348623158e+308 // max value
#define DBL_MAX_VALUE_10_EXP   308                     // max decimal exponent
#define DBL_MAX_VALUE_EXP      1024                    // max binary exponent
#define DBL_MIN_VALUE         2.2250738585072014e-308 // min positive value
#define DBL_TRUE_MIN_VALUE    4.9406564584124654e-324 // min positive value
#define FLT_MAX_VALUE          3.402823466e+38F        // max value
#define FLT_MIN_VALUE         1.175494351e-38F        // min normalized positive value
#define LDBL_MAX_VALUE         DBL_MAX_VALUE                 // max value
#define LDBL_MAX_VALUE_10_EXP  DBL_MAX_VALUE_10_EXP          // max decimal exponent
#define LDBL_MAX_VALUE_EXP     DBL_MAX_VALUE_EXP             // max binary exponent
#define LDBL_MIN_VALUE        DBL_MIN_VALUE                // min normalized positive value

extern const unsigned char* BranchCoverageData;
extern int BranchCoverageSize;
extern long long LibFuzzerRunRounds;
extern int TestCaseGenCount;
extern int CoverageCount;
extern int CoverageCountLast;

void BranchCoverageRegister(const unsigned char* data, int size);
void BranchCoverageStatistics(int branchId);
void BranchCoverageRecordTestCase();

void writeStringNum(long long num, char* buf, int width);
void writeTestCaseBin();

bool DataMapping_i8 (unsigned char* const dst, const unsigned char* const src, int size, int min, int max);
bool DataMapping_i16(unsigned char* const dst, const unsigned char* const src, int size, int min, int max);
bool DataMapping_i32(unsigned char* const dst, const unsigned char* const src, int size, int min, int max);
bool DataMapping_i64(unsigned char* const dst, const unsigned char* const src, int size, long long min, long long max);
bool DataMapping_u8 (unsigned char* const dst, const unsigned char* const src, int size, unsigned int min, unsigned int max);
bool DataMapping_u16(unsigned char* const dst, const unsigned char* const src, int size, unsigned int min, unsigned int max);
bool DataMapping_u32(unsigned char* const dst, const unsigned char* const src, int size, unsigned int min, unsigned int max);
bool DataMapping_u64(unsigned char* const dst, const unsigned char* const src, int size, unsigned long long min, unsigned long long max);
bool DataMapping_f32(unsigned char* const dst, const unsigned char* const src, int size, float  min, float  max);
bool DataMapping_f64(unsigned char* const dst, const unsigned char* const src, int size, double min, double max);