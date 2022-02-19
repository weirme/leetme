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
private:
    void solve(vector<int>& nums, int begin, int end) {
        if (begin >= end) return;
        int pivot = begin + rand()%(end-begin+1);
        swap(nums[begin], nums[pivot]);
        int i = begin, j = end;
        int x = nums[begin];
        while (i < j) {
            while (i < j && nums[j] >= x) j--;
            if (i < j) nums[i] = nums[j];
            while (i < j && nums[i] <= x) i++;
            if (i < j) nums[j] = nums[i];
        }
        nums[i] = x;
        solve(nums, begin, i-1);
        solve(nums, i+1, end);
    }
    
public:
    vector<int> sortArray(vector<int>& nums) {
        solve(nums, 0, nums.size()-1);
        return nums;
    }
};
