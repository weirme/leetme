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
public:
    vector<int> partitionLabels(string s) {
        vector<int> mp(128, 0);
        unordered_set<int> set;
        vector<int> res;
        int len = 0;
        for (char c : s) mp[c]++;
        for (int i = 0; i < s.size(); i++) {
            if (set.find(s[i]) == set.end()) set.insert(s[i]);
            if (--mp[s[i]] == 0) set.erase(s[i]);
            len++;
            if (set.empty()) {
                res.push_back(len);
                len = 0;
            }
        }
        return res;
    }
};

int main() {
    string s = "ababcbacadefegdehijhklij";
    Solution sol;
    vector<int> res = sol.partitionLabels(s);
    return 0;
}
