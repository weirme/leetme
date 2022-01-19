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

bool solve(int* pre, int pbegin, int pend, int* in, int ibegin, int iend) {
    if (pbegin > pend)
        return true;
    int root = pre[pbegin];
    int pos = ibegin;
    while (pos <= iend && in[pos] != root) {
        pos++;
    }
    if (pos > iend) return false;
    int nleft = pos - ibegin;
    return solve(pre, pbegin+1, pbegin+nleft, in, ibegin, pos-1)
        && solve(pre, pbegin+nleft+1, pend, in, pos+1, iend);
}

bool validateStackSequences(int* pushed, int pushedSize, int* popped, int poppedSize){
    return solve(pushed, 0, pushedSize-1, popped, 0, poppedSize-1);
}
