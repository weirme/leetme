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
    bool dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, int vi, int vj, string word, int pos) {
        static vector<int> dir = {-1, 0, 1, 0, -1};
        if (pos == word.size()) return true;
        if (!(0 <= vi && vi < board.size()) || !(0 <= vj && vj < board[0].size())) return false;
        if (visited[vi][vj]) return false;
        if (board[vi][vj] != word[pos]) return false;
        visited[vi][vj] = true;
        int i = 0;
        for (i = 0; i < 4; i++) {
            if (dfs(board, visited, vi+dir[i], vj+dir[i+1], word, pos+1)) break;
        }
        visited[vi][vj] = false;
        return i < 4;
    }
    
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, *new vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]
                    && dfs(board, visited, i, j, word, 0)) return true;
            }
        }
        return false;
    }
};
