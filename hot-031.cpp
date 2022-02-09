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
    void reverse(vector<int>::iterator begin, vector<int>::iterator end) {
        for (auto low = begin, high = end; low < high; low++, high--)
            swap(*low, *high);
    }
    
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() == 1) return;
        int i = nums.size()-2;
        while (i >= 0 && nums[i] >= nums[i+1]) i--;
        if (i >= 0) {
            int j = nums.size()-1;
            while (j >= 0 && nums[j] <= nums[i]) j--;
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin()+i+1, nums.end()-1);
    }
};
