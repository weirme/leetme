#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        const int N = nums.size() + 2;
        int arr[N];
        memset(arr, 0, sizeof(arr));
        for (vector<int>::iterator it = nums.begin(); it < nums.end(); it++)
            if (*it >=0 && *it < N) arr[*it] = 1;
        for (int i = 1; i < N+1; i++)
            if (arr[i] == 0) return i;
        return 0;
    }
};