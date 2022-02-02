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
    bool isValid(string& s, int low, int high) {
        while (low <= high) {
            if (s[low] != s[high])
                return false;
            low++;
            high--;
        }
        return true;
    }
public:
    bool validPalindrome(string s) {
        int low = 0, high = s.size()-1;
        int pos = 0, ch = 0;
        while (low <= high) {
            if (s[low] != s[high]) {
                return isValid(s, low+1, high) || isValid(s, low, high-1);
            }
            low++;
            high--;
        }
        return true;
    }
};
