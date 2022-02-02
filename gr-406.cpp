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
    bool static cmp(vector<int>& x, vector<int>& y) {
        return x[0] < y[0];
    }
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> res(people.size());
        for (int i = 0; i < res.size(); i++) {
            res[i] = {INF, INF};
        }
        sort(people.begin(), people.end(), cmp);
        int pos = 0;
        for (int i = 0; i < people.size(); i++) {
            pos = people[i][1];
            for (int j = 0; j < res.size(); j++) {
                if (pos > 0) {
                    if (res[j][0] >= people[i][0]) {
                        pos--;
                    }
                }
                else {
                    if (res[j][0] == INF) {
                        res[j] = people[i];
                        break;
                    }
                }
            }
        }
        return res;
    }
};
