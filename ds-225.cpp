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

class MyStack {
private:
    queue<int> que;
public:
    MyStack() {

    }
    
    void push(int x) {
        int n = que.size();
        que.push(x);
        while (n--) {
            int t = que.front();
            que.pop();
            que.push(t);
        }
    }
    
    int pop() {
        int res = top();
        que.pop();
        return res;
    }
    
    int top() {
        int res = que.front();
        return res;
    }
    
    bool empty() {
        return que.empty();
    }
};
