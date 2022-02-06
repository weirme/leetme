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
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for (auto& n : nums) {
            int pos = abs(n)-1;
            if (nums[pos] > 0)
                nums[pos] = -nums[pos];
        }
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) res.push_back(i+1);
        }
        return res;
    }
};
