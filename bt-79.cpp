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
    vector<vector<bool>> visited;
    
    bool dfs(vector<vector<char>>& board, string& word, int vi, int vj, int k) {
        if (k == word.size())
            return true;
        if (!(0 <= vi && vi < board.size()) || !(0 <= vj && vj < board[0].size()) || visited[vi][vj] || board[vi][vj] != word[k])
            return false;
        visited[vi][vj] = true;
        bool res = dfs(board, word, vi-1, vj, k+1)
                || dfs(board, word, vi+1, vj, k+1)
                || dfs(board, word, vi, vj-1, k+1)
                || dfs(board, word, vi, vj+1, k+1);
        visited[vi][vj] = false;
        return res;
    }
    
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            visited.push_back(*new vector<bool>(board[0].size(), 0));
        }
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (dfs(board, word, i, j, 0))
                    return true;
            }
        }
        return false;
    }
};
