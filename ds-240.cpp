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
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int i = 0, j = n-1;
        while (i < m && 0 <= j) {
            if (matrix[i][j] == target) return true;
            else if (matrix[i][j] < target) i++;
            else j--;
        }
        return false;
    }
};
