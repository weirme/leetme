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

class MinStack {
public:
    stack<int> val;
    stack<int> min_val;
    
    MinStack() {
        
    }
    
    void push(int x) {
        val.push(x);
        if (min_val.empty() || x < min_val.top())
            min_val.push(x);
        else
            min_val.push(min_val.top());
    }
    
    void pop() {
        val.pop();
        min_val.pop();
    }
    
    int top() {
        return val.top();
    }
    
    int min() {
        return min_val.top();
    }
};
