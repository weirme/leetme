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
    void solve(string& s, string& sol, vector<string>& res, vector<bool>& visited) {
        if (sol.size() == s.size()) {
            res.push_back(sol);
            return;
        }
        for (int i = 0; i < s.size(); i++) {
            if (visited[i]) continue;
            if (i > 0 && !visited[i-1] && s[i-1] == s[i]) continue;
            visited[i] = true;
            sol.push_back(s[i]);
            solve(s, sol, res, visited);
            sol.pop_back();
            visited[i] = false;
        }
    }
    
public:
    vector<string> permutation(string s) {
        sort(s.begin(), s.end());
        string sol;
        vector<string> res;
        vector<bool> visited(s.size(), false);
        solve(s, sol, res, visited);
        return res;
    }
};
