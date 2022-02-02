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
#include <algorithm>

using namespace std;

const int INF = 0x7fffffff;

class Solution {
private:
    bool static cmp(pair<char, int>& x, pair<char, int>& y) {
        return x.second > y.second;
    }
public:
    string frequencySort(string s) {
        vector<pair<char, int>> vec(128);
        for (int i = 0; i < vec.size(); i++) {
            vec[i] = make_pair(i, 0);
        }
        for (const auto& c : s) {
            vec[c].second++;
        }
        sort(vec.begin(), vec.end(), cmp);
        string res;
        for (int i = 0; i < vec.size() && vec[i].second > 0; i++) {
            while (vec[i].second--) {
                res.push_back(vec[i].first);
            }
        }
        return res;
    }
};
