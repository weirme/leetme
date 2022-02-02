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
    vector<int> twoSum(vector<int>& numbers, int target) {
        int low = 0, high = numbers.size()-1;
        vector<int> res(2);
        while (low < high) {
            if (numbers[low] + numbers[high] == target) {
                res[0] = low+1;
                res[1] = high+1;
                break;
            }
            else if (numbers[low] + numbers[high] < target)
                low++;
            else
                high--;
        }
        return res;
    }
};
