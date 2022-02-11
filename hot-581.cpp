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
    int findUnsortedSubarray(vector<int>& nums) {
        int l = 0, r = -1;
        int ma = nums[0], mi = nums[nums.size()-1];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] >= ma) ma = nums[i];
            else r = i;
        }
        for (int i = nums.size()-2; i >= 0; i--) {
            if (nums[i] <= mi) mi = nums[i];
            else l = i;
        }
        return r-l+1;
    }
};
