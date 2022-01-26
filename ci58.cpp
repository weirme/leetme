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
    string reverseWords(string s) {
        if (s.size() == 0)
            return s;
        auto low = s.begin(), high = low;
        int flag = (*low == ' ');
        while (high < s.end()) {
            if (*high == ' ') {
                if (flag == 0) {
                    flag = 1;
                    *low++ = *high++;
                }
                else {
                    high++;
                }
            }
            else {
                flag = 0;
                *low++ = *high++;
            }
        }
        low--;
        int len = low - s.begin() + 1;
        if (len <= 1)
            return s.substr(0, len);
        if (*low == ' ')
            low--;
        reverse(s.begin(), low);
        auto end = low;
        low = s.begin();
        high = low+1;
        while (high < end) {
            if (*high == ' ') {
                reverse(low, high-1);
                low = high+1;
                high += 2;
            }
            else {
                high++;
            }
        }
        reverse(low, end);
        len = end - s.begin() + 1;
        return s.substr(0, len);
    }
};

int main() {
    string str = "  a good   example  ";
    Solution s;
    string res = s.reverseWords(str);
    return 0;
}
