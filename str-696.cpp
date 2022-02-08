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
    int countBinarySubstrings(string s) {
        vector<int> cnt;
        char last = s[0];
        int cur = 1;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == last) cur++;
            else {
                cnt.push_back(cur);
                last = s[i];
                cur = 1;
            }
        }
        cnt.push_back(cur);
        int res = 0;
        for (int i = 0; i < cnt.size()-1; i++) {
            res += min(cnt[i], cnt[i+1]);
        }
        return res;
    }
};
