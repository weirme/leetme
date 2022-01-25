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
    vector<int> singleNumbers(vector<int>& nums) {
        int x = 0;
        vector<int> ret(2, 0);
        for (auto it = nums.begin(); it < nums.end(); it++) {
            x ^= *it;
        }
        x &= ~(x-1);
        for (auto it = nums.begin(); it < nums.end(); it++) {
            if ((*it & x) == 0)
                ret[0] ^= *it;
            else
                ret[1] ^= *it;
        }
        return ret;
    }
};
