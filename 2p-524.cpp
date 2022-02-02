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
    bool static cmp(string& s1, string& s2) {
        if (s1.size() == s2.size())
            return s1 < s2;
        return s1.size() > s2.size();
    }
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        sort(dictionary.begin(), dictionary.end(), cmp);
        string t;
        int p = 0, q = 0;
        for (int i = 0; i < dictionary.size(); i++) {
            t = dictionary[i];
            p = 0;
            q = 0;
            while (p < s.size() && q < t.size()) {
                if (s[p] == t[q]) {
                    q++;
                }
                p++;
            }
            if (q == t.size()) {
                return t;
            }
        }
        return "";
    }
};
