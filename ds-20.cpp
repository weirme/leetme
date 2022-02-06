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
#include <algorithm>

using namespace std;

const int INF = 0x7fffffff;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (int i = 0; i < s.size(); i++) {
            switch (s[i]) {
                case '(':
                case '[':
                case '{':
                    stk.push(s[i]);
                    break;
                case ')':
                    if (stk.empty() || stk.top() != '(') return false;
                    stk.pop();
                    break;
                case ']':
                    if (stk.empty() || stk.top() != '[') return false;
                    stk.pop();
                    break;
                case '}':
                    if (stk.empty() || stk.top() != '{') return false;
                    stk.pop();
                    break;
                default:
                    break;
            }
        }
        return stk.empty();
    }
};
