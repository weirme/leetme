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
#include <algorithm>

using namespace std;

const int INF = 0x7fffffff;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> sum(nums.size()+1, 0);
        for (int i = 1; i <= nums.size(); i++) {
            sum[i] = sum[i-1] + nums[i-1];
        }
        unordered_map<int, int> mp;
        for (int i = 0; i <= nums.size(); i++) {
            int mod = (sum[i]%k + k) % k;
            mp[mod]++;
        }
        int res = 0;
        for (auto [k, v] : mp) {
            res += v * (v-1) / 2;
        }
        return res;
    }
};
