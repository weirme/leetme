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
    bool isvalid(vector<int>& cur, vector<int>& times) {
        for (int i = 0; i < cur.size(); i++) {
            if (cur[i] != times[i]) return false;
        }
        return true;
    }
    
public:
    vector<int> findAnagrams(string s, string p) {
        if (s.size() < p.size()) return {};
        vector<int> cur(26, 0);
        vector<int> times(26, 0);
        vector<int> res;
        for (char c : p) times[c-'a']++;
        int l = 0, r = 0;
        while (r-l+1 < p.size()) {
            cur[s[r]-'a']++;
            r++;
        }
        while (r < s.size()) {
            cur[s[r]-'a']++;
            if (isvalid(cur, times)) {
                res.push_back(l);
            }
            cur[s[l]-'a']--;
            l++;
            r++;
        }
        return res;
    }
};

int main() {
    string s = "cbaebabacd", p = "abc";
    Solution sol;
    vector<int> res = sol.findAnagrams(s, p);
    return 0;
}
