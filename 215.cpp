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
private:
    int solve(vector<int>& nums, int left, int right, int k) {
        int i = left, j = right;
        int x = nums[left];
        while (i < j) {
            while (i < j && nums[j] >= x) j--;
            if (i < j) nums[i] = nums[j];
            while (i < j && nums[i] <= x) i++;
            if (i < j) nums[j] = nums[i];
        }
        nums[i] = x;
        if (i == k) return nums[i];
        if (i < k) return solve(nums, i+1, right, k);
        else return solve(nums, left, i-1, k);
    }
    
public:
    int findKthLargest(vector<int>& nums, int k) {
        return solve(nums, 0, nums.size()-1, nums.size()-k);
    }
};
