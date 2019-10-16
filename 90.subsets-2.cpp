#include <vector>

using namespace std;

class Solution {
private:
    vector< vector<int> > res;
    
public:
    vector< vector<int> > subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> cur;
        subsets(nums, 0, cur);
        return res;
    }
    
    void subsets(vector<int>& nums, int pos, vector<int>& cur) {
        res.push_back(cur);
        for (int i = pos; i < nums.size(); i++) {
            if (i == pos || nums[i-1] != nums[i]) {
                cur.push_back(nums[i]);
                subsets(nums, i+1, cur);
                cur.pop_back();
            }
        }
    }
};
