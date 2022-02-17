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
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int n : nums) mp[n]++;
        int res = 0;
        for (auto [k, v] : mp) {
            cout << k << " " << v << endl;
            if (v != 0 && mp.count(k+1) > 0)
                res = max(res, v+mp[k+1]);
        }
        return res;
    }
};

int main() {
    vector<int> nums = {1,2,3,4,6,5,-5,10,-1,-2,5,4,4,-1,7};
    Solution s;
    int n = s.findLHS(nums);
    return 0;
}
