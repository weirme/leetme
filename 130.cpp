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
    void dfs(vector<vector<char>>& board, int vi, int vj) {
        static vector<int> dir = {-1, 0, 1, 0, -1};
        if (!(0 <= vi && vi < board.size()) || !(0 <= vj && vj < board[0].size())) return;
        if (board[vi][vj] != 'O') return;
        board[vi][vj] = 0;
        for (int i = 0; i < 4; i++) {
            dfs(board, vi+dir[i], vj+dir[i+1]);
        }
    }
    
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O') dfs(board, i, 0);
            if (board[i][n-1] == 'O') dfs(board, i, n-1);
        }
        for (int j = 0; j < n; j++) {
            if (board[0][j] == 'O') dfs(board, 0, j);
            if (board[m-1][j] == 'O') dfs(board, m-1, j);
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 0) board[i][j] = 'O';
                else board[i][j] = 'X';
            }
        }
    }
};
