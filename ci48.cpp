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
public:
    int lengthOfLongestSubstring(string s) {
        size_t n = s.size();
        if (n == 0)
            return 0;
        vector<int> last(128, -1);
        int i = 0, j = 0;
        int res = 0;
        while (j < n) {
            int l = s[j];
            if (last[l] < i) {
                res = max(res, j-i+1);
            }
            else {
                i = last[l] + 1;
            }
            last[l] = j;
            j++;
        }
        return res;
    }
};
