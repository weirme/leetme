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
    bool search(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        int mid;
        while (left < right) {
            mid = left + (right-left)/2;
            if (nums[mid] < nums[right]) {
                if (nums[mid] < target && target <= nums[right]) left = mid+1;
                else right = mid;
            }
            else if (nums[mid] > nums[right]) {
                if (nums[left] <= target && target <= nums[mid]) right = mid;
                else left = mid+1;
            }
            else right--;
        }
        return nums[left] == target;
    }
};
