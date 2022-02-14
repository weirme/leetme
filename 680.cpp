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
#include "types.h"

using namespace std;

const int INF = 0x7fffffff;

class Solution {
private:
    bool valid(string s, int l, int r) {
        while (l < r) {
            if (s[l++] != s[r--]) return false;
        }
        return true;
    }
    
public:
    bool validPalindrome(string s) {
        int l = 0, r = s.size()-1;
        while (l < r) {
            if (s[l] == s[r]) {
                l++;
                r--;
            }
            else {
                return valid(s, l+1, r) || valid(s, l, r-1);
            }
        }
        return true;
    }
};
