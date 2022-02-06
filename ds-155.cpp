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
#include <algorithm>

using namespace std;

const int INF = 0x7fffffff;

class MinStack {
    stack<int> vl;
    stack<int> mi;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        vl.push(val);
        if (mi.empty()) mi.push(val);
        else mi.push(min(mi.top(), val));
    }
    
    void pop() {
        vl.pop();
        mi.pop();
    }
    
    int top() {
        return vl.top();
    }
    
    int getMin() {
        return mi.top();
    }
};
