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
        int low = 0, high = matrix.size()-1;
        int mid;
        while (low <= high) {
            mid = low + (high-low)/2;
            if (mid == high || (matrix[mid][0] <= target && matrix[mid+1][0] > target)) break;
            else if (matrix[mid][0] < target) low = mid+1;
            else high = mid-1;
        }
        int row = mid;
        low = 0;
        high = matrix[0].size()-1;
        while (low <= high) {
            mid = low + (high-low)/2;
            if (matrix[row][mid] == target) return true;
            else if (matrix[row][mid] < target) low = mid+1;
            else high = mid-1;
        }
        return false;
    }
};
