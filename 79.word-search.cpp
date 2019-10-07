#include <vector>
#include <string>

using namespace std;

template <class Ty1, class Ty2>
inline const pair<Ty1, Ty2> operator+(const pair<Ty1, Ty2>&p1, const pair<Ty1, Ty2>&p2) {
    pair<Ty1, Ty2> ret;
    ret.first = p1.first + p2.first;
    ret.second = p1.second + p2.second;
    return ret;
}

class Solution {
private:
    int M, N;
    pair<int, int> up = make_pair(0, -1),
                   down = make_pair(0, 1),
                   left = make_pair(-1, 0),
                   right = make_pair(1, 0);
    pair<int, int> start;
    
    bool traverse(vector< vector<char> > board, string word, pair<int, int> cur) {
        if (word.empty()) return true;
        if (cur.first < 0 || cur.first >= M || cur.second < 0 || cur.second >= N) return false;
        if (board[cur.first][cur.second] != word[0]) return false;
        board[cur.first][cur.second] = 0;
        string remain(word.begin()+1, word.end());
        return traverse(board, remain, cur + up)
            || traverse(board, remain, cur + down)
            || traverse(board, remain, cur + left)
            || traverse(board, remain, cur + right);
    }
    
public:
    bool exist(vector< vector<char> >& board, string word) {
        M = board.size();
        if (M == 0) return false;
        N = board[0].size();
        for (int i = 0; i < M; i++)
            for (int j = 0; j < N; j++)
                if (board[i][j] == word[0]) {
                    pair<int, int> cur = make_pair(i, j);
                    if (traverse(board, word, cur)) return true;
                }
        return false;
    }
};
