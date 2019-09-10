#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        const int N = nums.size();
        int pre = 0, cur = 0;
        int res = 0;
        int i = 0;
        while (cur < N-1) {
            for (; i <= pre; i++)
                cur = max(cur, i+nums[i]);
            pre = cur;
            res++;
        }
        return res;
    }
};
