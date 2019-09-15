#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int front = 0, end = nums.size()-1, mid;
        while (front <= end) {
            mid = (front + end) / 2;
            if (nums[mid] == target) return mid;
            else if (nums[front] <= nums[mid]) {
                if (nums[front] <= target && nums[mid] > target) end = mid - 1;
                else front = mid + 1;
            }
            else {
                if (nums[mid] < target && nums[end] >= target) front = mid + 1;
                else end = mid - 1;
            }
        }
        return -1;
    }
};