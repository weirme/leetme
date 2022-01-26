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

class MaxQueue {
private:
    queue<int> que;
    deque<int> deq;
    
public:
    MaxQueue() {
        
    }
    
    int max_value() {
        if (que.empty())
            return -1;
        return deq.front();
    }
    
    void push_back(int value) {
        que.push(value);
        
        while (!deq.empty() && deq.back() <= value) {
            deq.pop_back();
        }
        
        deq.push_back(value);
    }
    
    int pop_front() {
        if (que.empty())
            return -1;
        int ret = que.front();
        que.pop();
        if (deq.front() == ret)
            deq.pop_front();
        return ret;
    }
};
