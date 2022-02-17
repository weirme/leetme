#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <numeric>
#include "types.h"

using namespace std;

const int INF = 0x7fffffff;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0, mid = 0, right = nums.size()-1;
        while (mid <= right) {
            if (nums[mid] == 0) {
                swap(nums[mid++], nums[left++]);
            }
            else if (nums[mid] == 2) {
                swap(nums[mid], nums[right--]);
            }
            else mid++;
        }
    }
};
