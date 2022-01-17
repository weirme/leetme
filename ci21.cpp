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
    vector<int> exchange(vector<int>& nums) {
        if (nums.size() == 0)
            return nums;
        auto low = nums.begin();
        auto high = nums.end() - 1;
        int t;
        while (low < high) {
            while (low < high && *low & 1) low++;
            while (low < high && !(*high & 1)) high--;
            if (low < high) {
                t = *low;
                *low = *high;
                *high = t;
            }
        }
        return nums;
    }
};
