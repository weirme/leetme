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
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int len = flowerbed.size();
        if (len == 1) {
            return n == 0 || (n == 1 && flowerbed[0] == 0);
        }
        if (len == 2) {
            return n == 0 || (n == 1 && flowerbed[0] == 0 && flowerbed[1] == 0);
        }
        if (flowerbed[0] == 0 && flowerbed[1] == 0) {
            flowerbed[0] = 1;
            n--;
        }
        for (int i = 1; i < len-1; i++) {
            if (flowerbed[i-1] == 0 && flowerbed[i] == 0 && flowerbed[i+1] == 0) {
                flowerbed[i] = 1;
                n--;
            }
        }
        if (flowerbed[len-2] == 0 && flowerbed[len-1] == 0) {
            flowerbed[len-1] = 1;
            n--;
        }
        return n <= 0;
    }
};

int main() {
    vector<int> vec = {1,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,1,0,1,0,1,0,0,0,0,0,1,0,1};
    Solution s;
    s.canPlaceFlowers(vec, 10);
    return 0;
}
