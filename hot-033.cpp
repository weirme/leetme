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
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1;
        int mid;
        while (low <= high) {
            mid = low + (high-low)/2;
            if (nums[mid] == target) return mid;
            if (nums[mid] < nums[high]) {
                if (nums[mid] < target && target <= nums[high]) low = mid+1;
                else high = mid-1;
            }
            else if (nums[mid] > nums[high]) {
                if (nums[low] <= target && target < nums[mid]) high = mid-1;
                else low = mid+1;
            }
            else high--;
        }
        return -1;
    }
};
