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
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include "types.h"

using namespace std;

const int INF = 0x7fffffff;

class Solution {
public:
    int minArray(vector<int>& numbers) {
        int low = 0, high = numbers.size()-1;
        int mid = 0;
        while (low <= high) {
            mid = low + (high-low)/2;
            if (numbers[mid] < numbers[high]) high = mid;
            else if (numbers[mid] > numbers[high]) low = mid+1;
            else high--;
        }
        return numbers[mid];
    }
};
