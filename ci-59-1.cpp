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

class MaxQueue {
private:
    queue<int> que;
    deque<int> ma;
    
public:
    MaxQueue() {

    }
    
    int max_value() {
        return que.empty() ? -1 : ma.front();
    }
    
    void push_back(int value) {
        que.push(value);
        while (!ma.empty() && ma.back() < value) {
            ma.pop_back();
        }
        ma.push_back(value);
    }
    
    int pop_front() {
        if (que.empty()) return -1;
        int res = que.front();
        que.pop();
        if (res == ma.front())
            ma.pop_front();
        return res;
    }
};
