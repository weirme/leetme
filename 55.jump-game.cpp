#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        const int N = nums.size();
        int pre = 0, cur = 0;
        int i = 0;
        while (cur < N-1) {
            for (; i <= pre; i++) cur = max(cur, i+nums[i]);
            if (pre == cur) return false;
            pre = cur;
        }
        return true;
    }
};