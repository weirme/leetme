#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector< vector<int> > threeSum(vector<int>& nums) {
        set< vector<int> > res_set;
        sort(nums.begin(), nums.end());
        int t;
        for (vector<int>::iterator it = nums.begin(); it + 1 < nums.end() && *it <= 0; it++) {
            vector<int>::iterator front = it + 1, rear = nums.end() - 1;
            while (front < rear) {
                if (*it + *front + *rear < 0) front++;
                else if (*it + *front + *rear > 0) rear--;
                else {
                    int t_arr[] = {*it, *front, *rear};
                    vector<int> t_vec(t_arr, t_arr+3);
                    res_set.insert(t_vec);
                    t = *front;
                    front++;
                    rear--;
                }
            }
        }
        vector< vector<int> > res_vec(res_set.begin(), res_set.end());
        return res_vec;
    }
};