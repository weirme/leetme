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
    vector<int> exchange(vector<int>& nums) {
        int l = 0, r = nums.size()-1;
        while (l < r) {
            while (l < r && nums[l]&1) l++;
            while (l < r && (nums[r]&1) == 0) r--;
            if (l < r) swap(nums[l++], nums[r--]);
        }
        return nums;
    }
};
