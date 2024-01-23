#pragma once

#include <map>
#include <string>
#include <vector>


using namespace std;

class StateSearchBasicBranchRelation{
public:
    static void loadStateSearchBranchRelation(vector<pair<int, string>>& StateSearch_BranchReadGlobalVar, vector<pair<int, string>>& StateSearch_BranchWriteGlobalVar);
};