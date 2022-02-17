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
    void merge_sort(vector<pair<int, int>>& nums, vector<int>& res, int left, int right) {
        if (left >= right) return;
        int mid = left + (right-left)/2;
        merge_sort(nums, res, left, mid);
        merge_sort(nums, res, mid+1, right);
        merge(nums, res, left, mid, right);
    }
              
    void merge(vector<pair<int, int>>& nums, vector<int>& res, int left, int mid, int right) {
        static vector<pair<int, int>> tmp(nums.size());
        int i = mid, j = right, k = right;
        while (i >= 0 && j >= mid+1) {
            if (nums[i] <= nums[j]) tmp[k--] = nums[j--];
            else {
                res[nums[i].second] += j-mid;
                tmp[k--] = nums[i--];
            }
        }
        while (i >= 0) tmp[k--] = nums[i--];
        while (j >= mid+1) tmp[k--] = nums[j--];
        for (k = left; k <= right; k++) {
            nums[k] = tmp[k];
        }
    }
    
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<pair<int, int>> inums(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            inums[i] = {nums[i], i};
        }
        vector<int> res(nums.size(), 0);
        merge_sort(inums, res, 0, nums.size()-1);
        return res;
    }
};
