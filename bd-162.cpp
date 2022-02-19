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

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size()-1;
        int mid;
        while (left < right) {
            mid = left + (right-left)/2;
            if (mid < nums.size()-1 && nums[mid] < nums[mid+1]) left = mid+1;
            else right = mid;
        }
        return left;
    }
};
