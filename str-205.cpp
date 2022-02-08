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
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<int, int> mp1;
        unordered_map<int, int> mp2;
        for (int i = 0; i < s.size(); i++) {
            auto it1 = mp1.find(s[i]);
            auto it2 = mp2.find(t[i]);
            if (it1 == mp1.end() && it2 == mp2.end()) {
                mp1[s[i]] = t[i];
                mp2[t[i]] = s[i];
            }
            else if (it1 != mp1.end() && it2 != mp2.end()) {
                if (it1->second != t[i] || it2->second != s[i]) return false;
            }
            else return false;
        }
        return true;
    }
};
