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

bool solve(int * postorder, int begin, int end) {
    if (begin >= end)
        return true;
    int root = postorder[end];
    int i = end-1;
    while (i >= begin && postorder[i] > root)
        i--;
    int mid = i;
    while (i >= begin) {
        if (postorder[i--] > root)
            return false;
    }
    return solve(postorder, begin, mid) && solve(postorder, mid+1, end-1);
}

bool verifyPostorder(int* postorder, int postorderSize){
    return solve(postorder, 0, postorderSize-1);
}
