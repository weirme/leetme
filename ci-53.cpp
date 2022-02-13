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
    int search(vector<int>& nums, int target) {
        int first = 1, second = 0;
        int low = 0, high = nums.size()-1;
        int mid;
        while (low <= high) {
            mid = low + (high-low)/2;
            if (nums[mid] == target) {
                if (mid == 0 || nums[mid-1] != target) {
                    first = mid;
                    break;
                }
                else high = mid-1;
            }
            else if (nums[mid] < target) low = mid+1;
            else high = mid-1;
        }
        low = 0, high = nums.size()-1;
        while (low <= high) {
            mid = low + (high-low)/2;
            if (nums[mid] == target) {
                if (mid == nums.size()-1 || nums[mid+1] != target) {
                    second = mid;
                    break;
                }
                else low = mid+1;
            }
            else if (nums[mid] < target) low = mid+1;
            else high = mid-1;
        }
        return second-first+1;
    }
};
