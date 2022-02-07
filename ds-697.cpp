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
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int n : nums) {
            mp[n]++;
        }
        vector<int> vs;
        int mx = 0;
        for (auto [k, v] : mp) {
            if (v == mx) vs.push_back(k);
            else if (v > mx) {
                vs.clear();
                vs.push_back(k);
                mx = v;
            }
        }
        int res = nums.size();
        for (int v : vs) {
            auto low = nums.begin();
            while (*low != v) {
                low++;
            }
            auto high = nums.end()-1;
            while (*high != v) {
                high--;
            }
            if (res > high-low+1) res = high-low+1;
        }
        return res;
    }
};
