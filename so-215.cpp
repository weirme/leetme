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
    int search(vector<int>& nums, int low, int high, int k) {
        if (low <= high) {
            int x = nums[low];
            int i = low, j = high;
            while (i < j) {
                while (i < j && nums[j] >= x) j--;
                if (i < j) nums[i] = nums[j];
                while (i < j && nums[i] <= x) i++;
                if (i < j) nums[j] = nums[i];
            }
            nums[i] = x;
            if (i == k) return x;
            else if (i < k)
                return search(nums, i+1, high, k);
            else
                return search(nums, low, i-1, k);
        }
        return -1;
    }
    
public:
    int findKthLargest(vector<int>& nums, int k) {
        return search(nums, 0, nums.size()-1, nums.size()-k);
    }
};
