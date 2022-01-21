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
    int majorityElement(vector<int>& nums) {
        int cnt = 1;
        int last = INF;
        for (auto it = nums.begin(); it < nums.end(); it++) {
            if (*it == last)
                cnt++;
            else if (--cnt == 0) {
                last = *it;
                cnt = 1;
            }
        }
        return last;
    }
};
