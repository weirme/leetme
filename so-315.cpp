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
    void merge(vector<pair<int, int>>& nums, vector<int>& res, int begin, int mid, int end) {
        static vector<pair<int, int>> vec(nums.size());
        int i = mid, j = end, k = end;
        while (i >= begin && j >= mid+1) {
            if (nums[i].first <= nums[j].first) vec[k--] = nums[j--];
            else {
                res[nums[i].second] += j-mid;
                vec[k--] = nums[i--];
            }
        }
        while (i >= begin) vec[k--] = nums[i--];
        while (j >= mid+1) vec[k--] = nums[j--];
        for (k = begin; k <= end; k++) {
            nums[k] = vec[k];
        }
    }
    
    void merge_sort(vector<pair<int, int>>& nums, vector<int>& res, int begin, int end) {
        if (begin >= end) return;
        int mid = begin + (end - begin) / 2;
        merge_sort(nums, res, begin, mid);
        merge_sort(nums, res, mid+1, end);
        merge(nums, res, begin, mid, end);
    }
    
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<pair<int, int>> idx_nums(nums.size());
        vector<int> res(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            idx_nums[i] = {nums[i], i};
        }
        merge_sort(idx_nums, res, 0, nums.size()-1);
        return res;
    }
};

int main() {
    vector<int> nums = {1,2,7,8,5};
    Solution s;
    vector<int> res = s.countSmaller(nums);
    return 0;
}
