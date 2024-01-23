#pragma once

#include <map>
#include <string>
#include <vector>


using namespace std;

class StateSearchBasicBranchRegister{
public:
    static void loadStateSearchBranchData(map<int, string>& StateSearch_Branch, map<int, int>& StateSearch_Branch_Depth);
};