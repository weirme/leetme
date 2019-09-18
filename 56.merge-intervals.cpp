#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    static bool cmp(vector<int> x, vector<int> y) {
        return x[0] < y[0];
    }
    
    vector< vector<int> > merge(vector< vector<int> >& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        vector< vector<int> > res;
        const int N = intervals.size();
        if (!N) return res;
        vector<int> cur = intervals[0];
        for (int i = 1; i < N; i++) {
            if (intervals[i][0] <= cur[1]) cur[1] = max(cur[1], intervals[i][1]);
            else {
                res.push_back(cur);
                cur = intervals[i];
            }
        }
        res.push_back(cur);
        return res;
    }
};
