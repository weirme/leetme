#include <vector>

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
    pair<int, int> start, dest;
    int square_sum = 0;
    
public:
    int traverse(vector< vector<int> > grid, pair<int, int> cur, int num) {
        if (cur.first < 0 || cur.first >= M || cur.second < 0 || cur.second >= N) return 0;
        if (grid[cur.first][cur.second] == -1) return 0;
        num--;
        if (cur == dest) return num == 0;
        grid[cur.first][cur.second] = -1;
        int res = traverse(grid, cur + up, num)
                + traverse(grid, cur + down, num)
                + traverse(grid, cur + left, num)
                + traverse(grid, cur + right, num);
        return res;
    }
    
    int uniquePathsIII(vector< vector<int> >& grid) {
        M = grid.size();
        N = grid[0].size();
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (grid[i][j] == 1) start = make_pair(i, j);
                if (grid[i][j] == 2) dest = make_pair(i, j);
                if (grid[i][j] == 0) square_sum++;
            }
        }
        return traverse(grid, start, square_sum+2);
    }
};
