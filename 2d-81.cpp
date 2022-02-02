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
    bool search(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1;
        int mid;
        while (low <= high) {
            mid = low + (high-low)/2;
            if (nums[mid] == target)
                return true;
            if (nums[mid] < nums[high]) {
                if (nums[mid] < target && target <= nums[high])
                    low = mid+1;
                else
                    high = mid-1;
            }
            else if (nums[mid] > nums[high]) {
                if (nums[low] <= target && target < nums[mid])
                    high = mid-1;
                else
                    low = mid+1;
            }
            else
                high--;
        }
        return false;
    }
};