#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0, j = 0;
        int flag = 0;
        int pre = 0xffff;
        while (j < nums.size()) {
            if (nums[j] == pre) flag++;
            else flag = 0;
            if (flag < 2) {
                nums[i] = nums[j];
                pre = nums[i];
                i++;
            }
            j++;
        }
        nums.erase(nums.begin()+i, nums.end());
        return nums.size();
    }
};


int main() {
    int arr[] = {1,1,1,1,1,3,3,3,3};
    vector<int> nums(arr, arr+9);
    Solution s;
    int res = s.removeDuplicates(nums);
    return 0;
}
