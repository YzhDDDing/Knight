#pragma once
#include <vector>
#include <map>
#include <set>

class BitmapCov {
public:
    struct McdcBitmapResult {
        bool encNew;
        bool encRefineNew;
        std::set<unsigned int> encRefineOlds;
    };

	static unsigned char* munitBitmap;
	static int munitBitmapLength;
	
	static unsigned char* branchBitmap;
	static int branchBitmapLength;
	
	static unsigned char* condBitmap;
	static int condBitmapLength;
	
	static unsigned char* decBitmap;
	static int decBitmapLength;

	static unsigned int* mcdcDecTemp;
	static std::vector<std::set<unsigned int>*>* mcdcBitmap;
    static int mcdcBitmapLength;

    static unsigned char* mcdcMeta;

    static unsigned char* munitAllBitmap;
    static unsigned char* branchAllBitmap;
    static unsigned char* condAllBitmap;
    static unsigned char* decAllBitmap;
    static std::vector<std::set<unsigned int>*>* mcdcAllBitmap;

    static int munitCov;
    static int branchCov;
    static int condCov;
    static int decCov;
    static int mcdcCov;
    static int totalMcdcCov;



    static void init();

	static bool CondRecord(bool res, int condIdx);
	static bool CondAndMCDCRecord(bool res, int condIdx, int decCondIdx, int decIdx);

    static void CreateMCDCBitmap(std::vector<std::set<unsigned int>*>* mcdcBitmap, int bitmapLen);
    static void ClearMCDCBitmap(std::vector<std::set<unsigned int>*>* mcdcBitmap, int bitmapLen);
    static void DeleteMCDCBitmap(std::vector<std::set<unsigned int>*>* mcdcBitmap, int bitmapLen);
    //static void CreateMCDCTestCaseIndexVector(std::vector<std::vector<unsigned int>*>* mcdcAllBitmapTestCaseIndex, int bitmapLen);
    //static void DeleteMCDCTestCaseIndexVector(std::vector<std::vector<unsigned int>*>* mcdcAllBitmapTestCaseIndex, int bitmapLen);

    static void clearCurrentBitmap();
    static bool step();

    static bool processBitmap(unsigned char* bitmap, int bitmapLen, unsigned char* allBitmap, int& allCov);
    static McdcBitmapResult processMCDCBitmap(std::vector<std::set<unsigned int>*>* bitmap, int bitmapLen, std::vector<std::set<unsigned int>*>* allBitmap, std::vector< std::vector<unsigned int>*>* allBitmapTestCaseIndex, int currMcdcTestCaseIndex, unsigned int* allMcdcCov, unsigned char* mcdcMeta, int totalMcdcCov, int& allCov);

    static int CountOneInBinary(unsigned int n);


};


