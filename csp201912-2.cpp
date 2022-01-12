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

struct Coordinate {
    int x, y;
    
    Coordinate(int x, int y) {
        this->x = x;
        this->y = y;
    }
    
    bool friend operator<(const Coordinate& A, const Coordinate& B) {
        if (A.x < B.x) return true;
        if (A.x > B.x) return false;
        return A.y < B.y;
    }
    
    Coordinate friend operator+(Coordinate& A, Coordinate& B) {
        return Coordinate(A.x + B.x, A.y + B.y);
    }
};

const Coordinate direction1[4] = {
    Coordinate(-1, 0),
    Coordinate(1, 0),
    Coordinate(0, -1),
    Coordinate(0, 1)
};

const Coordinate direction2[4] = {
    Coordinate(-1, -1),
    Coordinate(-1, 1),
    Coordinate(1, -1),
    Coordinate(1, 1)
};

int main() {
    map<Coordinate, pair<int, int>> graph;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        graph[Coordinate(x, y)] = make_pair(0, 0);
    }
    for (auto elem : graph) {
        Coordinate coord = elem.first;
        for (auto dir : direction1) {
            Coordinate near = coord + dir;
            if (graph.find(near) != graph.end()) graph[near].first++;
        }
        for (auto dir : direction2) {
            Coordinate near = coord + dir;
            if (graph.find(near) != graph.end()) graph[near].second++;
        }
    }
    int res[5] = {0};
    for (auto elem : graph) {
        if (elem.second.first == 4)
            res[elem.second.second]++;
    }
    for (auto n : res) {
        cout << n << endl;
    }
	return 0;
}
