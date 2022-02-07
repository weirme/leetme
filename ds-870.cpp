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

class Solution {
private:
    bool static cmp(pair<int, int>& x, pair<int, int>& y) {
        return x.first < y.first;
    }
    
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<pair<int, int>> nums3(n);
        for (int i = 0; i < n; i++) {
            nums3[i] = {nums2[i], i};
        }
        sort(nums1.begin(), nums1.end());
        sort(nums3.begin(), nums3.end(), cmp);
        vector<bool> visited(n, false);
        vector<int> res(n);
        int i = 0, j = 0;
        while (i < n) {
            if (nums1[i] > nums3[j].first) {
                res[nums3[j].second] = nums1[i];
                visited[i] = true;
                j++;
            }
            i++;
        }
        i = 0;
        while (j < n) {
            while (visited[i]) i++;
            res[nums3[j].second] = nums1[i];
            visited[i] = true;
            j++;
        }
        return res;
    }
};
