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
private:
    int res = 0;
    
    void merge(vector<int>& nums, int low, int mid, int high) {
        static vector<int> tmp(nums.size());
        int i = mid, j = high, k = high;
        while (i >= low && j >= mid+1) {
            if (nums[i] > nums[j]) {
                res += j-mid;
                tmp[k--] = nums[i--];
            }
            else tmp[k--] = nums[j--];
        }
        while (i >= low) tmp[k--] = nums[i--];
        while (j >= mid+1) tmp[k--] = nums[j--];
        for (k = low; k <= high; k++) nums[k] = tmp[k];
    }
    
    void merge_sort(vector<int>& nums, int begin, int end) {
        if (begin >= end) return;
        int mid = begin + (end - begin) / 2;
        merge_sort(nums, begin, mid);
        merge_sort(nums, mid+1, end);
        merge(nums, begin, mid, end);
    }
    
public:
    int reversePairs(vector<int>& nums) {
        merge_sort(nums, 0, nums.size()-1);
        return res;
    }
};
