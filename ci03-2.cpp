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
#include <sstream>

using namespace std;

const int INF = 0x3f3f3f3f;

class Solution {
private:
    int countNum(vector<int>& nums, int low, int high) {
        int cnt = 0;
        for (auto it = nums.begin(); it < nums.end(); it++) {
            if (*it >= low && *it <= high)
                cnt++;
        }
        return cnt;
    }
    
public:
    int findRepeatNumber(vector<int>& nums) {
        size_t n = nums.size();
        int low = 1;
        int high = n-1;
        int mid;
        while (low <= high) {
            mid = low + ((high - low) >> 1);
            int cnt = countNum(nums, low, mid);
            if (low == high) {
                if (cnt > 1)
                    return low;
                break;
            }
            /* 前半有重复 */
            if (cnt > mid - low + 1)
                high = mid;
            /* 后半有重复 */
            else
                low = mid + 1;
        }
        return -1;
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        
        int ret = Solution().findRepeatNumber(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
