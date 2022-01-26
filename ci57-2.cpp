#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>

using namespace std;

const int INF = 0x3f3f3f3f;

class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> res;
        int low = 1, high = 2;
        int sum = 3;
        while (low < (target+1)/2) {
            if (sum == target) {
                vector<int> tmp;
                for (int i = low; i <= high; i++) {
                    tmp.push_back(i);
                }
                res.push_back(tmp);
                sum -= low;
                low++;
                high++;
                sum += high;
            }
            else if (sum < target) {
                high++;
                sum += high;
            }
            else {
                sum -= low;
                low++;
            }
                
        }
        return res;
    }
};
