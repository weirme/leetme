#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        const int M = matrix.size();
        if (!M) return res;
        const int N = matrix[0].size();
        int min_i = -1, max_i = M, min_j = -1, max_j = N;
        int i = 0, j = 0;
        while (res.size() < M*N) {
            while (j < max_j && res.size() < M*N) res.push_back(matrix[i][j++]);
            j--;
            i++;
            min_i++;
            while (i < max_i && res.size() < M*N) res.push_back(matrix[i++][j]);
            i--;
            j--;
            max_j--;
            while (j > min_j && res.size() < M*N) res.push_back(matrix[i][j--]);
            j++;
            i--;
            max_i--;
            while (i > min_i && res.size() < M*N) res.push_back(matrix[i--][j]);
            i++;
            j++;
            min_j++;
        }
        return res;
    }
};

