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
private:
    void solve(vector<int>& arr, int begin, int end, int k) {
        if (begin > end) return;
        int i = begin, j = end;
        int x = arr[i];
        while (i < j) {
            while (i < j && arr[j] >= x) j--;
            if (i < j) arr[i++] = arr[j];
            while (i < j && arr[i] <= x) i++;
            if (i < j) arr[j--] = arr[i];
        }
        arr[i] = x;
        if (i+1 == k) return;
        if (i+1 < k) solve(arr, i+1, end, k);
        else solve(arr, begin, i-1, k);
    }
    
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        solve(arr, 0, arr.size()-1, k);
        return *new vector<int>(arr.begin(), arr.begin()+k);
    }
}
