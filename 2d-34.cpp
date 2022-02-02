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

const int INF = 0x7fffffff;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2, -1);
        int n = nums.size();
        int low = 1, high = n;
        nums.insert(nums.begin(), -INF);
        nums.insert(nums.end(), INF);
        int mid;
        while (low <= high) {
            mid = low + (high-low)/2;
            if (nums[mid] == target && nums[mid-1] != target) {
                res[0] = mid-1;
                break;
            }
            else if (nums[mid] < target)
                low = mid+1;
            else
                high = mid-1;
        }
        low = 1;
        high = n;
        while (low <= high) {
            mid = low + (high-low)/2;
            if (nums[mid] == target && nums[mid+1] != target) {
                res[1] = mid-1;
                break;
            }
            else if (nums[mid] <= target)
                low = mid+1;
            else
                high = mid-1;
        }
        return res;
    }
};

int main() {
    vector<int> nums = {1};
    Solution s;
    s.searchRange(nums, 1);
    return 0;
}
