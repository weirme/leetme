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
    int findContentChildren(vector<int>& g, vector<int>& s) {
        if (s.size() == 0)
            return 0;
        int res = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        auto it1 = g.end()-1, it2 = s.end()-1;
        while (it1 >= g.begin() && it2 >= s.begin()) {
            if (*it1 <= *it2) {
                res++;
                it1--;
                it2--;
            }
            else {
                it1--;
            }
        }
        return res;
    }
};
