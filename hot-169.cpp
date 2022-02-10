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
    int majorityElement(vector<int>& nums) {
        int last = nums[0];
        int cur = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != last) {
                if (--cur == 0) {
                    last = nums[i];
                    cur = 1;
                }
            }
            else cur++;
        }
        return last;
    }
};
