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
#include <unordered_set>
#include <algorithm>
#include <numeric>
#include "types.h"

using namespace std;

const int INF = 0x7fffffff;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<int, int> mp1, mp2;
        for (int i = 0; i < s.size(); i++) {
            if(mp1.count(s[i]) == 0) {
                if (mp2.count(t[i]) == 0) {
                    mp1[s[i]] = t[i];
                    mp2[t[i]] = s[i];
                }
                else return false;
            }
            else if (mp1[s[i]] != t[i]) return false;
        }
        return true;
    }
};
