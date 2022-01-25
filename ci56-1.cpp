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
    int singleNumber(vector<int>& nums) {
        vector<int> sums(32, 0);
        int ret = 0;
        for (auto it = nums.begin(); it < nums.end(); it++) {
            for (int i = 0; i < 32; i++) {
                if (((*it >> i) & 0x1) != 0)
                    sums[i]++;
            }
        }
        for (int i = 0; i < 32; i++) {
            ret |= (sums[i] % 3) << i;
        }
        return ret;
    }
};
