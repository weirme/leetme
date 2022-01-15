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

class CQueue {
private:
    stack<int> in;
    stack<int> out;

public:
    CQueue() {
        
    }
    
    void appendTail(int value) {
        in.push(value);
    }
    
    int deleteHead() {
        if (out.empty()) {
            while (!in.empty()) {
                int t = in.top();
                in.pop();
                out.push(t);
            }
        }
        if (out.empty())
            return -1;
        int res = out.top();
        out.pop();
        return res;
    }
};
