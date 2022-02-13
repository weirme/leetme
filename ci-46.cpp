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
    bool valid(int a, int b) {
        return 10 <= a*10 + b && a*10 + b <= 25;
    }
public:
    int translateNum(int num) {
        vector<int> vec;
        while (num) {
            vec.push_back(num%10);
            num /= 10;
        }
        int n = vec.size();
        int a = 1, b = 1;
        int t;
        for (int i = n-2; i >= 0; i--) {
            if (valid(vec[i+1], vec[i])) t = a+b;
            else t = a;
            b = a;
            a = t;
        }
        return a;
    }
};
