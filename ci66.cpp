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
    vector<int> constructArr(vector<int>& a) {
        vector<int> res(a.size());
        vector<int> fw(a.size(), 1), bw(a.size(), 1);
        for (int i = 1; i < a.size(); i++) {
            fw[i] = fw[i-1] * a[i-1];
        }
        for (int i = a.size()-2; i >= 0; i--) {
            bw[i] = bw[i+1] * a[i+1];
        }
        for (int i = 0; i < a.size(); i++) {
            res[i] = fw[i] * bw[i];
        }
        return res;
    }
};
