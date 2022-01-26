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
    void reverse(string::iterator low, string::iterator high) {
        while (low < high) {
            swap(*low++, *high--);
        }
    }
    
public:
    string reverseLeftWords(string s, int n) {
        reverse(s.begin(), s.begin()+n-1);
        reverse(s.begin()+n, s.end()-1);
        reverse(s.begin(), s.end()-1);
        return s;
    }
};
