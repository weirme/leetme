#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <numeric>
#include "types.h"

using namespace std;

const int INF = 0x7fffffff;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0) nums[i] += nums[i-1];
            res += mp[nums[i]-k];
            mp[nums[i]]++;
        }
        return res;
    }
};
