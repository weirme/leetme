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
    int solve(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size();
        int n = nums2.size();
        int id1 = 0, id2 = 0;
        while (true) {
            if (id1 == m) return nums2[id2+k-1];
            if (id2 == n) return nums1[id1+k-1];
            if (k == 1) return min(nums1[id1], nums2[id2]);
            int newid1 = min(id1+k/2-1, m-1);
            int newid2 = min(id2+k/2-1, n-1);
            if (nums1[newid1] <= nums2[newid2]) {
                k -= newid1 - id1 + 1;
                id1 = newid1 + 1;
            }
            else {
                k -= newid2 - id2 + 1;
                id2 = newid2 + 1;
            }
        }
    }
    
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size() + nums2.size();
        if (n%2) return solve(nums1, nums2, (n+1)/2);
        else return (solve(nums1, nums2, n/2) + solve(nums1, nums2, n/2+1)) * 0.5;
    }
};
