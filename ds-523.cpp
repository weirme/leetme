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
    bool checkSubarraySum(vector<int>& nums, int k) {
        vector<int> sum(nums.size()+1, 0);
        unordered_set<int> set;
        for (int i = 1; i <= nums.size(); i++) {
            sum[i] = sum[i-1] + nums[i-1];
        }
        for (int i = 2; i <= nums.size(); i++) {
            set.insert(sum[i-2]%k);
            if (set.find(sum[i]%k) != set.end()) return true;
        }
        return false;
    }
};
