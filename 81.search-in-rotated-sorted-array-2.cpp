#include <vector>

using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int front = 0, end = nums.size()-1;
        int mid;
        while (front <= end) {
            mid = (front + end) / 2;
            if (nums[mid] == target) return true;
            else if (nums[mid] < nums[end]) {
                if (nums[mid] < target && target <= nums[end]) front = mid + 1;
                else end = mid - 1;
            }
            else if (nums[mid] > nums[end]) {
                if (nums[front] <= target && target < nums[mid]) end = mid - 1;
                else front = mid + 1;
            }
            else end--;
        }
        return false;
    }
};
