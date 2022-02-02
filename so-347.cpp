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
#include <algorithm>

using namespace std;

const int INF = 0x3f3f3f3f;

class Solution {
private:
    bool static cmp(pair<int, int>& x, pair<int, int>& y) {
        return x.second > y.second;
    }
    
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }
        vector<pair<int, int>> bucket;
        for (const auto& item : mp) {
            bucket.push_back(make_pair(item.first, item.second));
        }
        sort(bucket.begin(), bucket.end(), cmp);
        vector<int> res(k);
        for (int i = 0; i < k; i++) {
            res[i] = bucket[i].first;
        }
        return res;
    }
};
