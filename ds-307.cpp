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

using namespace std;

const int INF = 0x7fffffff;

class NumArray {
    vector<int> nums;
    vector<int> sum;
public:
    NumArray(vector<int>& nums) {
        this->nums = nums;
        sum = *new vector<int>(nums.size()+1, 0);
        for (int i = 1; i <= nums.size(); i++) {
            sum[i] = sum[i-1] + nums[i-1];
        }
    }
    
    void update(int index, int val) {
        int delta = val - nums[index];
        nums[index] = val;
        for (int i = index+1; i <= nums.size(); i++) {
            sum[i] += delta;
        }
    }
    
    int sumRange(int left, int right) {
        return sum[right+1] - sum[left];
    }
};
