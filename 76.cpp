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
    bool valid(vector<int>& cnt, vector<int>& mp) {
        for (int i = 0; i < mp.size(); i++) {
            if (cnt[i] < mp[i]) return false;
        }
        return true;
    }
    
public:
    string minWindow(string s, string t) {
        vector<int> cnt(128, 0);
        vector<int> mp(128, 0);
        for (char c : t) mp[c]++;
        int l = 0, r = 0;
        int begin = 0, len = s.size()+1;
        while (r < s.size()) {
            cnt[s[r]]++;
            while (valid(cnt, mp)) {
                if (r-l+1 < len) {
                    len = r-l+1;
                    begin = l;
                }
                cnt[s[l]]--;
                l++;
            }
            r++;
        }
        return len == s.size()+1 ? "" : s.substr(begin, len);
    }
};

int main() {
    string s = "ADOBECODEBANC", t = "ABC";
    Solution sol;
    string res = sol.minWindow(s, t);
    return 0;
}
