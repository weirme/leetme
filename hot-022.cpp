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
    void solve(string& sol, vector<string>& res, int left, int right, int n) {
        if (sol.size() == n * 2) {
            res.push_back(sol);
            return;
        }
        if (left < n) {
            sol.push_back('(');
            solve(sol, res, left+1, right, n);
            sol.pop_back();
        }
        if (right < left) {
            sol.push_back(')');
            solve(sol, res, left, right+1, n);
            sol.pop_back();
        }
    }
    
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string sol;
        solve(sol, res, 0, 0, n);
        return res;
    }
};
