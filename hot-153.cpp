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
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size()-1;
        int mid;
        int res = INF;
        while (low <= high) {
            mid = low + (high-low)/2;
            res = min(res, nums[mid]);
            if (nums[mid] < nums[high]) {
                high = mid-1;
            }
            else if (nums[mid] > nums[high]) {
                low = mid+1;
            }
            else high--;
        }
        return res;
    }
};
