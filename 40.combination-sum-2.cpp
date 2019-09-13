#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector< vector<int> > combinationSum2(vector<int>& candidates, int target) {
        set< vector<int> > res;
        sort(candidates.begin(), candidates.end());
        for (vector<int>::iterator it = candidates.begin(); it < candidates.end(); it++) {
            if (*it > target) break;
            if (*it == target) {
                vector<int> t;
                t.push_back(*it);
                res.insert(t);
                break;
            }
            vector<int> remain = vector<int>(it+1, candidates.end());
            vector< vector<int> > temp = combinationSum2(remain, target - *it);
            for(vector< vector<int> >::iterator temp_it = temp.begin(); temp_it < temp.end(); temp_it++) {
                temp_it->insert(temp_it->begin(), *it);
                res.insert(*temp_it);
            }
        }
        vector< vector<int> > ret(res.begin(), res.end());
        return ret;
    }
};