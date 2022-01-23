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
#include <algorithm>

using namespace std;

const int INF = 0x3f3f3f3f;

class Solution {
private:
    int ret = 0;
    vector<int> nums;
    vector<int> vec;
    void merge(int begin, int end) {
        if (begin >= end)
            return;
        
        int mid = begin + (end - begin) / 2;
        merge(begin, mid);
        merge(mid+1, end);
        
        int i = begin, j = mid+1, k = begin;
        while (i <= mid && j <= end) {
            if (nums[i] <= nums[j]) {
                vec[k++] = nums[i++];
            }
            else {
                vec[k++] = nums[j++];
                ret += (mid-i+1);
            }
        }
        while (i <= mid) {
            vec[k++] = nums[i++];
        }
        while (j <= end) {
            vec[k++] = nums[j++];
        }
        
        for (k = begin; k <= end; k++) {
            nums[k] = vec[k];
        }
    }
    
public:
    int reversePairs(vector<int>& nums) {
        this->nums = nums;
        vec = *new vector<int>(nums.size(), 0);
        merge(0, nums.size()-1);
        return ret;
    }
};


int main() {
    vector<int> nums = {7, 5, 6, 4};
    Solution s;
    int ret = s.reversePairs(nums);
    return 0;
}
