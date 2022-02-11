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

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<bool>> g(numCourses, *new vector<bool>(numCourses, false));
        vector<int> degree(numCourses, 0);
        for (auto& v : prerequisites) {
            g[v[1]][v[0]] = true;
            degree[v[0]]++;
        }
        queue<int> que;
        int n = numCourses;
        for (int i = 0; i < numCourses; i++) {
            if (degree[i] == 0) que.push(i);
        }
        if (que.empty()) return false;
        while (!que.empty()) {
            int v = que.front();
            que.pop();
            n--;
            for (int i = 0; i < numCourses; i++) {
                if (g[v][i] && --degree[i] == 0) {
                    que.push(i);
                }
            }
        }
        return n == 0;
    }
};
