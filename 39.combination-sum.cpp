#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector< vector<int> > combinationSum(vector<int>& candidates, int target) {
        vector< vector<int> > res;
        sort(candidates.begin(), candidates.end());
        for (vector<int>::iterator it = candidates.begin(); it < candidates.end(); it++) {
            if (*it > target) break;
            if (*it == target) {
                vector<int> t;
                t.push_back(*it);
                res.push_back(t);
                break;
            }
            vector<int> remain = vector<int>(it, candidates.end());
            vector< vector<int> > temp = combinationSum(remain, target - *it);
            for(vector< vector<int> >::iterator temp_it = temp.begin(); temp_it < temp.end(); temp_it++) {
                temp_it->insert(temp_it->begin(), *it);
                res.push_back(*temp_it);
            }
        }
        return res;
    }
};