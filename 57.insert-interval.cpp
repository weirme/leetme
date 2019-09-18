#include <vector>
#include <algorithm>

using namespace std;

class GreatThan {
public:
    GreatThan(vector<int> vec) : vec(vec) {}
    bool operator() (vector<int> x) {
        return x[0] > vec[0];
    }
private:
    vector<int> vec;
};

class Solution {
public:
    vector<int> newInterval;
    
    vector< vector<int> > insert(vector< vector<int> >& intervals, vector<int>& newInterval) {
        vector< vector<int> > res;
        this->newInterval = newInterval;
        auto it = find_if(intervals.begin(), intervals.end(), GreatThan(newInterval));
        intervals.insert(it, newInterval);
        const int N = intervals.size();
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


int main() {
    vector< vector<int> > intervals;
    intervals.push_back({1, 3});
    intervals.push_back({6, 9});
    vector<int> newInterval;
    newInterval.push_back(2);
    newInterval.push_back(5);
    Solution s;
    vector< vector<int> > res = s.insert(intervals, newInterval);
}
