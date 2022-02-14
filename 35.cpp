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
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        int mid;
        while (left < right) {
            mid = left + (right-left)/2;
            if (nums[mid] < target) left = mid+1;
            else right = mid;
        }
        return nums[left] < target ? left+1 : left;
    }
};
