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
private:
    const vector<string> mp = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    void solve(string digits, int pos, string& sol, vector<string>& res) {
        if (sol.size() == digits.size()) {
            res.push_back(sol);
            return;
        }
        for (auto c : mp[digits[pos]-'0']) {
            sol.push_back(c);
            solve(digits, pos+1, sol, res);
            sol.pop_back();
        }
    }
    
public:
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) return {};
        vector<string> res;
        string sol;
        solve(digits, 0, sol, res);
        return res;
    }
};
