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
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0)
            return 0;
        int low = 0, high = nums.size()-1;
        int mid = 0;
        int left = 1, right = 0;
        while (low <= high) {
            mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                if (mid == 0 || nums[mid-1] != target) {
                    left = mid;
                    break;
                }
                else {
                    high = mid - 1;
                }
            }
            else if (nums[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        low = 0;
        high = nums.size() - 1;
        while (low <= high) {
            mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                if (mid == nums.size()-1 || nums[mid+1] != target) {
                    right = mid;
                    break;
                }
                else {
                    low = mid + 1;
                }
            }
            else if (nums[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return right - left + 1;
    }
};
