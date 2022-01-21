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
    static bool cmp(string a, string b) {
        return a + b < b + a;
    }

public:
    string minNumber(vector<int>& nums) {
        vector<string> arr;
        for (auto it = nums.begin(); it < nums.end(); it++) {
            arr.push_back(to_string(*it));
        }
        sort(arr.begin(), arr.end(), cmp);
        string res;
        for (auto it = arr.begin(); it < arr.end(); it++) {
            res += *it;
        }
        return res;
    }
};
