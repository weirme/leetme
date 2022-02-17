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

const int INF = 0x7fffffff;

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<int, int> mp;
        for (char c : s) mp[c]++;
        int flag = 0;
        int res = 0;
        for (auto [k, v] : mp) {
            if (v == 0) continue;
            if (v&1) {
                flag = 1;
                res += v-1;
            }
            else res += v;
        }
        return res+flag;
    }
};
