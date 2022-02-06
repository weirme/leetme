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

class MyQueue {
private:
    stack<int> s1;
    stack<int> s2;
    
public:
    MyQueue() {

    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        int res = peek();
        s2.pop();
        return res;
    }
    
    int peek() {
        if (s2.empty()) {
            while (!s1.empty()) {
                int t = s1.top();
                s1.pop();
                s2.push(t);
            }
        }
        int res = s2.top();
        return res;
    }
    
    bool empty() {
        return s1.empty() && s2.empty();
    }
};
