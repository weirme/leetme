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
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hash;
        for (auto& n : nums) hash.insert(n);
        int res = 0;
        while (!hash.empty()) {
            int v = *(hash.begin());
            hash.erase(v);
            int i = v-1;
            int cur = 1;
            while (1) {
                auto it = hash.find(i--);
                if (it == hash.end()) break;
                hash.erase(it);
                cur++;
            }
            i = v+1;
            while (1) {
                auto it = hash.find(i++);
                if (it == hash.end()) break;
                hash.erase(it);
                cur++;
            }
            res = max(res, cur);
        }
        return res;
    }
};
