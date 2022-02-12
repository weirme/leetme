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
    bool solve(vector<int>& postorder, int begin, int end) {
        if (begin >= end) return true;
        int i = end-1;
        while (begin <= i && postorder[i] > postorder[end]) {
            i--;
        }
        int mid = i;
        while (begin <= i) {
            if (postorder[i--] >= postorder[end]) return false;
        }
        return solve(postorder, begin, mid) && solve(postorder, mid+1, end-1);
    }
    
public:
    bool verifyPostorder(vector<int>& postorder) {
        return solve(postorder, 0, postorder.size()-1);
    }
};
