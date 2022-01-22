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
    char firstUniqChar(string s) {
        size_t n = s.size();
        if (n == 0)
            return ' ';
        vector<int> vec(128, 0);
        for (auto it = s.begin(); it < s.end(); it++)
            vec[*it]++;
        for (auto it = s.begin(); it < s.end(); it++) {
            if (vec[*it] == 1)
                return *it;
        }
        return ' ';
    }
};
