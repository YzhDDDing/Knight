#include "BitmapCov.h"
#include <string.h>
unsigned char* BitmapCov::munitBitmap = nullptr;
int BitmapCov::munitBitmapLength = 0;

unsigned char* BitmapCov::branchBitmap = nullptr;
int BitmapCov::branchBitmapLength = 0;

unsigned char* BitmapCov::condBitmap = nullptr;
int BitmapCov::condBitmapLength = 0;

unsigned char* BitmapCov::decBitmap = nullptr;
int BitmapCov::decBitmapLength = 0;

unsigned int* BitmapCov::mcdcDecTemp = nullptr;
std::vector<std::set<unsigned int>*>* BitmapCov::mcdcBitmap = nullptr;
int BitmapCov::mcdcBitmapLength = 0;

unsigned char* BitmapCov::mcdcMeta = nullptr;

unsigned char* BitmapCov::munitAllBitmap = nullptr;
unsigned char* BitmapCov::branchAllBitmap = nullptr;
unsigned char* BitmapCov::condAllBitmap = nullptr;
unsigned char* BitmapCov::decAllBitmap = nullptr;
std::vector<std::set<unsigned int>*>* BitmapCov::mcdcAllBitmap = nullptr;

int BitmapCov::munitCov = 0;
int BitmapCov::branchCov = 0;
int BitmapCov::condCov = 0;
int BitmapCov::decCov = 0;
int BitmapCov::mcdcCov = 0;
int BitmapCov::totalMcdcCov = 0;


//unsigned int* BitmapCov::mcdcDecTemp = nullptr;
//std::vector<std::set<unsigned int>*>* BitmapCov::mcdcBitmap = nullptr;
//int BitmapCov::mcdcBitmapLength = 0;

void BitmapCov::init()
{
    munitCov = 0;
    branchCov = 0;
    condCov = 0;
    decCov = 0;
    mcdcCov = 0;
    totalMcdcCov = 0;
    
    for (int k = 0; k < BitmapCov::mcdcBitmapLength; k++) {
        totalMcdcCov += BitmapCov::mcdcMeta[k];
    }
    munitAllBitmap = new unsigned char[BitmapCov::munitBitmapLength];
    memset(munitAllBitmap, 0, BitmapCov::munitBitmapLength * sizeof(unsigned char));
    branchAllBitmap = new unsigned char[BitmapCov::branchBitmapLength];
    memset(branchAllBitmap, 0, BitmapCov::branchBitmapLength * sizeof(unsigned char));
    condAllBitmap = new unsigned char[BitmapCov::condBitmapLength];
    memset(condAllBitmap, 0, BitmapCov::condBitmapLength * sizeof(unsigned char));
    decAllBitmap = new unsigned char[BitmapCov::decBitmapLength];
    memset(decAllBitmap, 0, BitmapCov::decBitmapLength * sizeof(unsigned char));
    mcdcAllBitmap = new std::vector<std::set<unsigned int>*>();
    BitmapCov::CreateMCDCBitmap(mcdcAllBitmap, BitmapCov::mcdcBitmapLength);

    //std::vector<std::vector<unsigned int>*>* mcdcAllBitmapTestCaseIndex = new std::vector<std::vector<unsigned int>*>();
    //BitmapCov::CreateMCDCTestCaseIndexVector(mcdcAllBitmapTestCaseIndex, BitmapCov::mcdcBitmapLength);
    unsigned int* allMcdcCov = new unsigned int[BitmapCov::mcdcBitmapLength];
    memset(allMcdcCov, 0, BitmapCov::mcdcBitmapLength * sizeof(unsigned int));
    BitmapCov::munitBitmap = new unsigned char[BitmapCov::munitBitmapLength];
    memset(munitBitmap, 0, BitmapCov::munitBitmapLength * sizeof(unsigned char));
    BitmapCov::branchBitmap = new unsigned char[BitmapCov::branchBitmapLength];
    memset(branchBitmap, 0, BitmapCov::branchBitmapLength * sizeof(unsigned char));
    BitmapCov::condBitmap = new unsigned char[BitmapCov::condBitmapLength];
    memset(condBitmap, 0, BitmapCov::condBitmapLength * sizeof(unsigned char));
    BitmapCov::decBitmap = new unsigned char[BitmapCov::decBitmapLength];
    memset(decBitmap, 0, BitmapCov::decBitmapLength * sizeof(unsigned char));
    BitmapCov::mcdcDecTemp = new unsigned int[BitmapCov::mcdcBitmapLength];
    memset(mcdcDecTemp, 0, BitmapCov::mcdcBitmapLength * sizeof(unsigned char));
    BitmapCov::mcdcBitmap = new std::vector<std::set<unsigned int>*>();
    BitmapCov::CreateMCDCBitmap(BitmapCov::mcdcBitmap, BitmapCov::mcdcBitmapLength);
}

bool BitmapCov::CondRecord(bool res, int condIdx)
{
	if (condIdx >= 0) {
		// handle condition
		if (res) {
			BitmapCov::condBitmap[condIdx] = 1;
		}
		else {
			BitmapCov::condBitmap[condIdx+1] = 1;
		}
	}
	else {
		// handle decision
		if (res) {
			// for decision id, it is set to decid+1 when parameter incoming. 
			// thus, here need to -1. 
			BitmapCov::decBitmap[(-condIdx-1)] = 1;
		}
		else {
			BitmapCov::decBitmap[(-condIdx-1)+1] = 1;
		}
	}
	return res;
}

bool BitmapCov::CondAndMCDCRecord(bool res, int condIdx, int decCondIdx, int decIdx)
{
	BitmapCov::CondRecord(res, condIdx);

    	// handle mcdc
    //	if (vect.size() == 0) {
    //		vect.push_back(0);
    //	}
    //	int lastPos = vect.size() - 1;
    BitmapCov::mcdcDecTemp[decIdx] |= ((res ? 1 : 0) << decCondIdx);
    //	vect[lastPos] |= ((res ? 1 : 0) << decCondIdx);
    if (decCondIdx == 0) {
    //		vect.push_back(0);
    	std::set<unsigned int>* vect = BitmapCov::mcdcBitmap->at(decIdx);
    	vect->insert(BitmapCov::mcdcDecTemp[decIdx]);
    	BitmapCov::mcdcDecTemp[decIdx] = 0;
    }
    //	BitmapCov::mcdcBitmap[decIdx] = vect;
	return res;
}


void BitmapCov::CreateMCDCBitmap(std::vector<std::set<unsigned int>*>* mcdcBitmap, int bitmapLen)
{
    for (int i = 0; i < bitmapLen; i++) {
        std::set<unsigned int>* s = new std::set<unsigned int>();
        mcdcBitmap->push_back(s);
    }
}
void BitmapCov::ClearMCDCBitmap(std::vector<std::set<unsigned int>*>* mcdcBitmap, int bitmapLen)
{
    for (int i = 0; i < bitmapLen; i++) {
        std::set<unsigned int>* s = mcdcBitmap->at(i);
        s->clear();
    }
}
void BitmapCov::DeleteMCDCBitmap(std::vector<std::set<unsigned int>*>* mcdcBitmap, int bitmapLen)
{
    for (int i = 0; i < bitmapLen; i++) {
        std::set<unsigned int>* s = mcdcBitmap->at(i);
        delete s;
    }
    delete mcdcBitmap;
}
//void BitmapCov::CreateMCDCTestCaseIndexVector(std::vector<std::vector<unsigned int>*>* mcdcAllBitmapTestCaseIndex, int bitmapLen)
//{
//    for (int i = 0; i < bitmapLen; i++) {
//        std::vector<unsigned int>* v = new std::vector<unsigned int>();
//        mcdcAllBitmapTestCaseIndex->push_back(v);
//    }
//}
//void BitmapCov::DeleteMCDCTestCaseIndexVector(std::vector<std::vector<unsigned int>*>* mcdcAllBitmapTestCaseIndex, int bitmapLen)
//{
//    for (int i = 0; i < bitmapLen; i++) {
//        std::vector<unsigned int>* v = mcdcAllBitmapTestCaseIndex->at(i);
//        delete v;
//    }
//    delete mcdcAllBitmapTestCaseIndex;
//}

void BitmapCov::clearCurrentBitmap()
{
    memset(BitmapCov::munitBitmap, 0, BitmapCov::munitBitmapLength);
    memset(BitmapCov::branchBitmap, 0, BitmapCov::branchBitmapLength);
    memset(BitmapCov::condBitmap, 0, BitmapCov::condBitmapLength);
    memset(BitmapCov::decBitmap, 0, BitmapCov::decBitmapLength);
    ClearMCDCBitmap(BitmapCov::mcdcBitmap, BitmapCov::mcdcBitmapLength);
}

bool BitmapCov::step()
{

    bool enc_new1 = processBitmap(BitmapCov::munitBitmap, BitmapCov::munitBitmapLength, munitAllBitmap, munitCov);
    //if (enc_new1) {
    //    TestCase* tc = new TestCase(testcaseId, buffLen, BitmapCov::munitBitmapLength, TestCase::BitmapType::munit);
    //    //	memcpy(buffer, tc->buff, tc->buffSize);
    //    memcpy(tc->buff, buffer, buffLen);
    //    memcpy(tc->munitBitmap, BitmapCov::munitBitmap, BitmapCov::munitBitmapLength);
    //    munitTcases.push_back(tc);
    //}
    bool enc_new2 = processBitmap(BitmapCov::branchBitmap, BitmapCov::branchBitmapLength, branchAllBitmap, branchCov);
    //if (enc_new2) {
    //    TestCase* tc = new TestCase(testcaseId, buffLen, BitmapCov::branchBitmapLength, TestCase::BitmapType::branch);
    //    //	memcpy(buffer, tc->buff, tc->buffSize);
    //    memcpy(tc->buff, buffer, buffLen);
    //    memcpy(tc->branchBitmap, BitmapCov::branchBitmap, BitmapCov::branchBitmapLength);
    //    branchTcases.push_back(tc);
    //}
    bool enc_new3 = processBitmap(BitmapCov::condBitmap, BitmapCov::condBitmapLength, condAllBitmap, condCov);
    //if (enc_new3) {
    //    TestCase* tc = new TestCase(testcaseId, buffLen, BitmapCov::condBitmapLength, TestCase::BitmapType::condition);
    //    //	memcpy(buffer, tc->buff, tc->buffSize);
    //    memcpy(tc->buff, buffer, buffLen);
    //    memcpy(tc->condBitmap, BitmapCov::condBitmap, BitmapCov::condBitmapLength);
    //    condTcases.push_back(tc);
    //}
    bool enc_new4 = processBitmap(BitmapCov::decBitmap, BitmapCov::decBitmapLength, decAllBitmap, decCov);
    //if (enc_new4) {
    //    TestCase* tc = new TestCase(testcaseId, buffLen, BitmapCov::decBitmapLength, TestCase::BitmapType::decision);
    //    //	memcpy(buffer, tc->buff, tc->buffSize);
    //    memcpy(tc->buff, buffer, buffLen);
    //    memcpy(tc->decBitmap, BitmapCov::decBitmap, BitmapCov::decBitmapLength);
    //    decTcases.push_back(tc);
    //}
    //int mcdcCurrTid = mcdcTcases.size();
    //McdcBitmapResult encNew5 = processMCDCBitmap(BitmapCov::mcdcBitmap, BitmapCov::mcdcBitmapLength, mcdcAllBitmap, mcdcAllBitmapTestCaseIndex, mcdcCurrTid, allMcdcCov, mcdcMeta, totalMcdcCov, mcdcCov, mcdcCovDetail, "MCDCCoverage");
    //if (encNew5.encNew) {
    //    TestCase* tc = new TestCase(testcaseId, buffLen, BitmapCov::mcdcBitmapLength, TestCase::BitmapType::mcdc);
    //    // memcpy(buffer, tc->buff, tc->buffSize);
    //    memcpy(tc->buff, buffer, buffLen);
    //    for (int i = 0; i < BitmapCov::mcdcBitmapLength; i++) {
    //        std::set<unsigned int>* mcdcBitmapSetI = BitmapCov::mcdcBitmap->at(i);
    //        std::set<unsigned int>* tcI = tc->mcdcBitmap->at(i);
    //        tcI->insert(mcdcBitmapSetI->begin(), mcdcBitmapSetI->end());
    //        //		tc->mcdcBitmap[i].assign(BitmapCov::mcdcBitmap[i].begin(), BitmapCov::mcdcBitmap[i].end());
    //    }
    //    //	memcpy(tc->mcdc_bitmap, BitmapCov::mcdcBitmap, BitmapCov::mcdcBitmapLength * sizeof(unsigned int));
    //    mcdcTcases.push_back(tc);
    //    assert(mcdcCurrTid == mcdcTcases.size() - 1);
    //    if (encNew5.encRefineNew) {
    //        mcdcRefineTcaseIds.insert(mcdcCurrTid);
    //        mcdcRefineTcaseIds.insert(encNew5.encRefineOlds.begin(), encNew5.encRefineOlds.end());
    //    }
    //}
    return enc_new2;
}

bool BitmapCov::processBitmap(unsigned char* bitmap, int bitmapLen, unsigned char* allBitmap, int& allCov)
{
    int inMunitCov = 0;
    for (int k = 0; k < bitmapLen; k++) {
        allBitmap[k] = allBitmap[k] | bitmap[k];
    }
    for (int k = 0; k < bitmapLen; k++) {
        if (allBitmap[k] > 0) {
            inMunitCov++;
        }else {
        }
    }
    bool retTrue = false;
    if (allCov < inMunitCov) {
        allCov = inMunitCov;
        retTrue = true;
    }
    if (retTrue) {
        return true;
    }
    return false;
}

/*BitmapCov::McdcBitmapResult BitmapCov::processMCDCBitmap(std::vector<std::set<unsigned int>*>* bitmap, int bitmapLen, std::vector<std::set<unsigned int>*>* allBitmap, std::vector< std::vector<unsigned int>*>* allBitmapTestCaseIndex, int currMcdcTestCaseIndex, unsigned int* allMcdcCov, unsigned char* mcdcMeta, int totalMcdcCov, int& allCov)
{
    McdcBitmapResult res = {false, false};
    bool newCov = false;
    for (int i = 0; i < bitmapLen; i++) {
        std::set<unsigned int>* bitmapi = bitmap->at(i);
        //		assert(bitmapi->size() == 0 || bitmapi->size() >= 2);
        //		if (bitmapi->size() <= 1) {
            //			continue;
            //		}
        //		bitmapi.pop_back();
        //		std::sort(bitmapi.begin(), bitmapi.end());
        //		bitmapi.erase(std::unique(bitmapi.begin(), bitmapi.end()), bitmapi.end());
        std::set<unsigned int>* allBitmapI = allBitmap->at(i);
        std::vector<unsigned int>* allBitmapTestCaseIndexI = allBitmapTestCaseIndex->at(i);
        for (std::set<unsigned int>::iterator it = bitmapi->begin(); it != bitmapi->end(); it++) {
            unsigned int bits = *it;
            bool seen_before = false;
            std::set<unsigned int>::iterator it2 = allBitmapI->begin();
            std::vector<unsigned int>::iterator idxIt2 = allBitmapTestCaseIndexI->begin();
            for (; it2 != allBitmapI->end() && idxIt2 != allBitmapTestCaseIndexI->end(); it2++, idxIt2++) {
                unsigned int allBits = *it2;
                unsigned int allBitsIndex = *idxIt2;
                unsigned int iRes = bits ^ allBits;
                if (iRes == 0) {
                    seen_before = true;
                    break;
                }
                unsigned int decisionFlipped = iRes & 1;
                unsigned int conditionFlipped = iRes >> 1;
                unsigned int minusOne = conditionFlipped - 1;
                bool onlyOneConditionFlipped = ((conditionFlipped & minusOne) == 0);
                if (decisionFlipped && onlyOneConditionFlipped) {
                    int origin = allMcdcCov[i];
                    allMcdcCov[i] |= conditionFlipped;
                    if (origin != allMcdcCov[i]) {
                        res.encRefineNew = true;
                        res.encRefineOlds.insert(allBitsIndex);
                    }
                }
            }
            if (!seen_before) {
                res.encNew = true;
                allBitmapI->insert(bits);
                allBitmapTestCaseIndexI->push_back(currMcdcTestCaseIndex);
            }
            if (res.encRefineNew) {
                //assert(res.encNew);
            }
        }
        //		allBitmap[i] = allBitmapI;
        //		allBitmapTestCaseIndex[i] = allBitmapTestCaseIndexI;
    }
    int inMunitCov = 0;
    //std::cout << extraInfo << "_Bitmap: ";
    for (int k = 0; k < bitmapLen; k++) {
        int numO = CountOneInBinary(allMcdcCov[k]);
        //allCovDetail += SPrintBinary(mcdcMeta[k], allMcdcCov[k]);
        inMunitCov += numO;
    }
    //std::cout << allCovDetail;
    //std::cout << std::endl;
    allCov = inMunitCov;
    //printf("%d turn executed, %s: %d/%d;\n", turns, extraInfo.c_str(), inMunitCov, totalMcdcCov);
    return res;
}*/

int BitmapCov::CountOneInBinary(unsigned int n)
{
    int count = 0;
    for (; n != 0; count++) {
        n = n & (n - 1);
    }
    return count;
}