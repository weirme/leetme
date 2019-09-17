#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    const int MAX = 1e8;

    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int res = MAX;
        int pre, cur;
        for (auto it = nums.begin(); it < nums.end()-2; it++) {
            auto front = it+1, rear = nums.end()-1;
            pre = MAX;
            while (front < rear) {
                cur = *it + *front + *rear;
                if (pre*cur > 0 && abs(pre-target) < abs(cur-target)) break;
                res = abs(cur-target) < abs(res-target) ? cur : res;
                pre = cur;
                if (cur < target) front++;
                else if (cur > target) rear--;
                else return cur;
            }
        }
        return res;
    }
};

#include <iostream>

int main() {
    int arr[] = {-55,-24,-18,-11,-7,-3,4,5,6,9,11,23,33};
    vector<int> nums(arr, arr+13);
    Solution s;
    int res = s.threeSumClosest(nums, 0);
    cout << res << endl;
}
