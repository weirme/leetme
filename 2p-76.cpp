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
    string minWindow(string s, string t) {
        vector<int> need(128, 0);
        vector<bool> flag(128, false);
        for (int i = 0; i < t.size(); i++) {
            need[t[i]]++;
            flag[t[i]] = true;
        }
        int cnt = 0, l = 0, min_l = 0, min_size = s.size()+1;
        for (int r = 0; r < s.size(); r++) {
            if (flag[s[r]]) {
                if (--need[s[r]] >= 0) {
                    cnt++;
                }
            }
            while (cnt == t.size()) {
                if (r-l+1 < min_size) {
                    min_l = l;
                    min_size = r-l+1;
                }
                if (flag[s[l]] && ++need[s[l]] > 0) {
                    cnt--;
                }
                l++;
            }
        }
        return min_size > s.size() ? "" : s.substr(min_l, min_size);
    }
};
