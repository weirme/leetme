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
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0) return {-1, -1};
        int begin = -1, end = -1;
        int left = 0, right = nums.size()-1;
        int mid;
        while (left < right) {
            mid = left + (right-left)/2;
            if (nums[mid] < target) left = mid+1;
            else right = mid;
        }
        if (nums[left] == target) begin = left;
        left = 0;
        right = nums.size()-1;
        while (left < right) {
            mid = left + (right-left+1)/2;
            if (nums[mid] > target) right = mid-1;
            else left = mid;
        }
        if (nums[left] == target) end = left;
        return {begin, end};
    }
};
