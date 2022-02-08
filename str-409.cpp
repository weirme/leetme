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

using namespace std;

const int INF = 0x7fffffff;

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<int, int> mp;
        for (auto c : s) mp[c]++;
        int res = 0;
        int flag = 0;
        for (auto& [k, v] : mp) {
            if (v%2 == 0) res += v;
            else {
                res += v-1;
                flag = 1;
            }
        }
        return res+flag;
    }
};
