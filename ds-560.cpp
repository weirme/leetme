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
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int res = 0;
        int cur = 0;
        for (int i = 0; i < nums.size(); i++) {
            cur += nums[i];
            res += mp[cur-k];
            mp[cur]++;
        }
        return res;
    }
};

int main() {
    vector<int> nums = {1,1,1};
    Solution s;
    s.subarraySum(nums, 2);
    return 0;
}
