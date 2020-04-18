#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

const int INF = 0x3f3f3f3f;

struct Time {
    int h, m, s;
    int p;
    int begin;
    
    int arrive() {
        return h * 3600 + m * 60 + s;;
    }
    
    int end() {
        return begin + p * 60;
    }
    
    int wait() {
        return begin - arrive();
    }
};

struct cmp1 {
    bool operator()(Time& a, Time& b) {
        return a.arrive() > b.arrive();
    }
};

struct cmp2 {
    bool operator()(Time& a, Time& b) {
        return a.end() > b.end() ;
    }
};

int main() {
    priority_queue<Time, vector<Time>, cmp1> wait;
    priority_queue<Time, vector<Time>, cmp2> que;
    int k, n;
    scanf("%d%d", &k, &n);
    while (k--) {
        int h, m, s, p;
        scanf("%d:%d:%d %d", &h, &m, &s, &p);
        if (p > 60) p = 60;
        if (h < 17 || (h == 17 && !m && !s))
            wait.push({h, m, s, p});
    }
    int cnt = wait.size();
    float res = 0;
    while (n-- && !wait.empty()) {
        Time t = wait.top();
        wait.pop();
        t.begin = max(8 * 3600, t.arrive());
        que.push(t);
    }
    while (!que.empty()) {
        Time cur = que.top();
        que.pop();
        res += cur.wait();
        if (!wait.empty()) {
            Time next = wait.top();
            wait.pop();
            next.begin = max(cur.end(), next.arrive());
            que.push(next);
        }
    }
    res /= cnt;
    res /= 60;
    printf("%.1f", res);
	return 0;
}
