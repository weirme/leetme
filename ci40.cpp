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
private:
    void sift(vector<int>& arr, int n) {
        for (int t = n/2; t > 0; t--) {
            int i = t;
            int j = 2 * i;
            while (j <= n) {
                if (j < n && arr[j+1] < arr[j]) j++;
                if (arr[i] < arr[j])
                    break;
                swap(arr[i], arr[j]);
                i = j;
                j = 2 * i;
            }
        }
    }
    
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        arr.insert(arr.begin(), 0);
        int n = arr.size();
        vector<int> res(k);
        for (int i = 0; i < k; i++) {
            sift(arr, n-i-1);
            res[i] = arr[1];
            swap(arr[1], arr[n-i-1]);
        }
        return res;
    }
};
