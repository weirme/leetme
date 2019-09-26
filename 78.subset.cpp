#include <vector>

using namespace std;

class Solution {
public:
    vector< vector<int> > subsets(vector<int>& nums) {
        vector< vector<int> > res;
        if (nums.size() == 0) {
            vector<int> temp;
            res.push_back(temp);
            return res;
        }
        int cur = *nums.begin();
        vector<int> remain(nums.begin()+1, nums.end());
        res = subsets(remain);
        int n = res.size();
        for (int i = 0; i < n; i++) {
            vector<int> temp;
            temp.push_back(cur);
            temp.insert(temp.end(), res[i].begin(), res[i].end());
            res.push_back(temp);
        }
        return res;
    }
};


int main() {
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    Solution s;
    vector< vector<int> > res = s.subsets(vec);
    return 0;
}
