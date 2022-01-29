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
    int add(int a, int b) {
        int sum = 0;
        int carry = 0;
        do {
            sum  = a ^ b;
            carry = (a & b) << 1;
            a = sum;
            b = carry;
        } while (b);
        return sum;
    }
};
