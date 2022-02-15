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
    void reverse(vector<int>& nums, int left, int right) {
        while (left < right) {
            swap(nums[left++], nums[right--]);
        }
    }
    
public:
    void nextPermutation(vector<int>& nums) {
        int right = nums.size()-1;
        int i = right-1;
        int ma = nums[right];
        while (i >= 0 && nums[i] >= ma) ma = nums[i--];
        if (i >= 0) {
            int j = right;
            while (nums[j] <= nums[i]) j--;
            swap(nums[i], nums[j]);
        }
        reverse(nums, i+1, right);
    }
};
