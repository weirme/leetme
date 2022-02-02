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
    bool static cmp(pair<int, int>& x, pair<int, int>& y) {
        return x.first < y.first;
    }
    
public:
    vector<int> partitionLabels(string s) {
        vector<pair<int, int>> vec(26, make_pair(-1, -1));
        for (int i = 0; i < s.size(); i++) {
            if (vec[s[i]-'a'].first == -1)
                vec[s[i]-'a'].first = i;
            vec[s[i]-'a'].second = i;
        }
        vector<int> res;
        sort(vec.begin(), vec.end(), cmp);
        int i = 0;
        while (vec[i].first == -1) {
            i++;
        }
        int begin = vec[i].first;
        int end = vec[i].second;
        for (i += 1; i < 26; i++) {
            if (vec[i].first == -1)
                continue;
            if (vec[i].first > end) {
                res.push_back(end-begin+1);
                begin = vec[i].first;
                end = vec[i].second;
            }
            else {
                end = max(end, vec[i].second);
            }
        }
        res.push_back(end-begin+1);
        return res;
    }
};
