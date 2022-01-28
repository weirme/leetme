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
    bool isStraight(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int x = 0;
        int i = 0;
        while (nums[i] == 0) {
            x++;
            i++;
        }
        int last = INF;
        while (i < nums.size()) {
            if (last != INF && (x -= (nums[i] - last - 1)) < 0)
                return false;
            if (last == nums[i])
                return false;
            last = nums[i];
            i++;
        }
        return true;
    }
};
