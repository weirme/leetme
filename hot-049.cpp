#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include "types.h"

using namespace std;

const int INF = 0x7fffffff;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> vec = strs;
        vector<vector<string>> res;
        unordered_map<string, vector<string>> mp;
        for (auto& s : vec) {
            sort(s.begin(), s.end());
        }
        for (int i = 0; i < vec.size(); i++) {
            if (mp.find(vec[i]) == mp.end()) mp[vec[i]] = {strs[i]};
            else mp[vec[i]].push_back(strs[i]);
        }
        for (auto& [k, v] : mp) {
            res.push_back(v);
        }
        return res;
    }
};
