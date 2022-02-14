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
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0, high = nums.size()-1;
        int mid;
        while (low < high) {
            mid = low + (high-low)/2;
            if (mid&1) {
                if (mid > 0 && nums[mid-1] == nums[mid]) low = mid+1;
                else high = mid;
            }
            else {
                if (mid+1 < nums.size() && nums[mid+1] == nums[mid]) low = mid+1;
                else high = mid;
            }
        }
        return nums[low];
    }
};
