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
#include <algorithm>

using namespace std;

const int INF = 0x3f3f3f3f;

class Solution {
private:
    vector<string> res;
    string str;
    
    void solve(int idx) {
        if (idx == str.size()) {
            res.push_back(*new string(str));
            return;
        }
        for (int i = idx; i < str.size(); i++) {
            char c = str[idx];
            str[idx] = str[i];
            str[i] = c;
            
            solve(idx+1);
            
            c = str[idx];
            str[idx] = str[i];
            str[i] = c;
        }
    }
    
public:
    vector<string> permutation(string s) {
        if (s.size() > 0) {
            str = s;
            solve(0);
        }
        return res;
    }
};
