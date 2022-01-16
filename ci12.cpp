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
    vector<vector<bool>> visited;
    size_t m;
    size_t n;
    size_t len;
    
    bool search(vector<vector<char>>& board, string word, int i, int j, int t) {
        if (t == len) return true;
        if (!(0 <= i && i < m) || !(0 <= j && j < n) || visited[i][j]) return false;
        if (board[i][j] != word[t]) return false;
        visited[i][j] = true;
        if (search(board, word, i-1, j, t+1) ||
            search(board, word, i+1, j, t+1) ||
            search(board, word, i, j-1, t+1) ||
            search(board, word, i, j+1, t+1))
            return true;
        visited[i][j] = false;
        return false;
    }

    
public:
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        if (m == 0) return false;
        n = board[0].size();
        if (n == 0) return false;
        len = word.size();
        if (len == 0) return true;
        for (int i = 0; i < m; i++) {
            vector<bool> vec(n);
            for (int j = 0; j < n; j++) vec[j] = false;
            visited.push_back(vec);
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (search(board, word, i, j, 0) == true)
                    return true;
            }
        }
        return false;
    }
};
