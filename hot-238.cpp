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
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include "types.h"

using namespace std;

const int INF = 0x7fffffff;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> fore(n+2, 1);
        vector<int> back(n+2, 1);
        for (int i = 1; i <= n; i++) {
            fore[i] = fore[i-1] * nums[i-1];
        }
        for (int i = n; i > 0; i--) {
            back[i] = back[i+1] * nums[i-1];
        }
        vector<int> res(n);
        for (int i = 1; i <= n; i++) {
            res[i-1] = fore[i-1] * back[i+1];
        }
        return res;
    }
};
