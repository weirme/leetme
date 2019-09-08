#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        const int N = height.size();
        if (N == 0) return 0;
        int left_max[N], right_max[N];
        int left_t = 0, right_t = 0;
        for (int i = 0; i < N; i++) {
            left_t = max(left_t, height[i]);
            left_max[i] = left_t;
            right_t = max(right_t, height[N-i-1]);
            right_max[N-i-1] = right_t;
        }
        int res = 0;
        for (int i = 0; i < N; i++)
            res += max(0, min(left_max[i], right_max[i]) - height[i]);
        return res;
    }
};
