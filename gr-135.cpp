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
    int candy(vector<int>& ratings) {
        vector<int> candy(ratings.size(), 1);
        for (int i = 1; i < ratings.size(); i++) {
            if (ratings[i-1] < ratings[i]) candy[i] = candy[i-1] + 1;
        }
        for (int i = ratings.size()-2; i >= 0; i--) {
            if (ratings[i] > ratings[i+1] && candy[i] <= candy[i+1]) candy[i] = candy[i+1] + 1;
        }
        int sum = 0;
        for (int i = 0; i < candy.size(); i++) {
            sum += candy[i];
        }
        return sum;
    }
};
