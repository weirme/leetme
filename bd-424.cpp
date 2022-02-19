#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <numeric>
#include "types.h"

using namespace std;

class Solution {
private:
    int getmax(vector<int>& mp) {
        int res = 0;
        for (int n : mp) res = max(res, n);
        return res;
    }
    
public:
    int characterReplacement(string s, int k) {
        vector<int> mp(128, 0);
        int l = 0, r = 0;
        int res = 1;
        while (r < s.size()) {
            mp[s[r]]++;
            while (l < r && r-l+1 - getmax(mp) > k) {
                mp[s[l]]--;
                l++;
            }
            res = max(res, r-l+1);
            r++;
        }
        return res;
    }
};
