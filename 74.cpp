#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <numeric>
#include "types.h"

using namespace std;

const int INF = 0x7fffffff;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int left = 0, right = m*n-1;
        int mid = 0;
        while (left < right) {
            mid = left + (right-left)/2;
            if (matrix[mid/n][mid%n] < target) left = mid+1;
            else right = mid;
        }
        return matrix[left/n][left%n] == target;
    }
};
