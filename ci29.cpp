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
    int i0, im;
    int j0, jm;
    vector<int> res;
    
    void solve(vector<vector<int>>& matrix) {
        while (i0 <= im && j0 <= jm) {
            for (int j = j0; j <= jm; j++)
                res.push_back(matrix[i0][j]);
            if (++i0 > im)
                break;
            for (int i = i0; i <= im; i++)
                res.push_back(matrix[i][jm]);
            if (--jm < j0)
                break;
            for (int j = jm; j >= j0; j--)
                res.push_back(matrix[im][j]);
            if (--im < i0)
                break;
            for (int i = im; i >= i0; i--)
                res.push_back(matrix[i][j0]);
            if (++j0 > jm)
                break;
        }
    }
    
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        size_t m = matrix.size();
        if (m == 0) return res;
        size_t n = matrix[0].size();
        if (n == 0) return res;
        i0 = 0; im = m-1;
        j0 = 0; jm = n-1;
        solve(matrix);
        return res;
    }
};
