#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int front = 0, end = nums.size()-1;
        int res[] = {-1, -1};
        int mid;
        while (front <= end) {
            mid = (front + end) / 2;
            if (nums[mid] < target) front = mid+1;
            else if (nums[mid] > target) end = mid-1;
            else {
                res[0] = mid;
                end = mid-1;
            }
        }
        front = 0;
        end = nums.size()-1;
        while (front <= end) {
            mid = (front + end) / 2;
            if (nums[mid] < target) front = mid+1;
            else if (nums[mid] > target) end = mid-1;
            else {
                res[1] = mid;
                front = mid+1;
            }
        }
        return vector<int>(res, res+2);
    }
};