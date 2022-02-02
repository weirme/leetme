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
#include <algorithm>

using namespace std;

const int INF = 0x3f3f3f3f;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0, high = nums.size()-1;
        int mid = 0;
        while (low <= high) {
            mid = low + (high-low)/2;
            if (mid == 0 || mid == nums.size()-1 || (nums[mid-1] != nums[mid] && nums[mid] != nums[mid+1]))
                return nums[mid];
            if (mid & 1) {
                if (nums[mid-1] == nums[mid])
                    low = mid+1;
                else
                    high = mid-1;
            }
            else {
                if (nums[mid-1] == nums[mid])
                    high = mid-1;
                else
                    low = mid+1;
            }
        }
        return nums[mid];
    }
};
