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
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        if (nums.size() == 0)
            return res;
        auto low = nums.begin(), high = nums.end()-1;
        while (low <= high) {
            if (*low + *high == target) {
                res.push_back(*low);
                res.push_back(*high);
                break;            }
            else if (*low + *high < target)
                low++;
            else
                high--;
        }
        return res;
    }
};
