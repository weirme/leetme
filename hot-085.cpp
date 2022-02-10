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
    int solve(vector<int> height) {
        height.insert(height.begin(), 0);
        height.push_back(0);
        stack<int> stk;
        int res = 0;
        for (int i = 0; i < height.size(); i++) {
            while (!stk.empty() && height[stk.top()] > height[i]) {
                int top = stk.top();
                stk.pop();
                int l = stk.top()+1;
                int r = i-1;
                res = max(res, (r-l+1) * height[top]);
            }
            stk.push(i);
        }
        return res;
    }
    
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> height(n, 0);
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '0') height[j] = 0;
                else height[j]++;
            }
            res = max(res, solve(height));
        }
        return res;
    }
};

int main() {
    vector<vector<char>> matrix = {{'1','0'},{'1','0'}};
    Solution s;
    int res = s.maximalRectangle(matrix);
    return 0;
}
