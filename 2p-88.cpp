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
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p = m-1, q = n-1, r = m+n-1;
        while (p >= 0 && q >= 0) {
            if (nums1[p] < nums2[q])
                nums1[r--] = nums2[q--];
            else
                nums1[r--] = nums1[p--];
        }
        while (q >= 0) {
            nums1[r--] = nums2[q--];
        }
    }
};
