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

class MinStack {
private:
    stack<int> val;
    stack<int> mi;
    
public:
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int x) {
        val.push(x);
        if (mi.empty()) mi.push(x);
        else mi.push(::min(x, mi.top()));
    }
    
    void pop() {
        val.pop();
        mi.pop();
    }
    
    int top() {
        return val.top();
    }
    
    int min() {
        return mi.top();
    }
};
