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
private:
    vector<pair<int, int>> points;
    
    void dfs(vector<vector<char>>& board, int vi, int vj) {
        if (!(0 <= vi && vi < board.size()) || !(0 <= vj && vj < board[0].size()))
            return;
        if (board[vi][vj] == 'X')
            return;
        board[vi][vj] = 'X';
        points.push_back({vi, vj});
        dfs(board, vi-1, vj);
        dfs(board, vi+1, vj);
        dfs(board, vi, vj-1);
        dfs(board, vi, vj+1);
    }
    
public:
    void solve(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i++) {
            if (board[i][0] == 'O') dfs(board, i, 0);
            if (board[i][board[0].size()-1] == 'O') dfs(board, i, board[0].size()-1);
        }
        for (int j = 0; j < board[0].size(); j++) {
            if (board[0][j] == 'O') dfs(board, 0, j);
            if (board[board.size()-1][j] == 'O') dfs(board, board.size()-1, j);
        }
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++)
                board[i][j] = 'X';
        }
        for (auto& [i, j] : points) {
            board[i][j] = 'O';
        }
    }
};

int main() {
    vector<vector<char>> board = {{'O','X','X','O','X'},{'X','O','O','X','O'},{'X','O','X','O','X'},{'O','X','O','O','O'},{'X','X','O','X','O'}};
    Solution s;
    s.solve(board);
    return 0;
}
