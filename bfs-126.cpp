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

class Solution {
private:
    bool isvalid(string& x, string& y) {
        bool flag = true;
        for (int i = 0; i < x.size(); i++) {
            if (x[i] != y[i]) {
                if (flag) flag = false;
                else return false;
            }
        }
        return true;
    }
    
    void get_path(int i, vector<int>& previous, vector<string>& wordList, vector<string>& path) {
        if (previous[i] != -1) {
            get_path(previous[i], previous, wordList, path);
        }
        path.push_back(wordList[i]);
    }
    
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<bool> visited(wordList.size(), false);
        vector<int> previous(wordList.size());
        vector<vector<string>> res;
        wordList.insert(wordList.begin(), beginWord);
        queue<int> que;
        que.push(0);
        visited[0] = true;
        previous[0] = -1;
        while (!que.empty()) {
            int cur = que.front();
            que.pop();
            if (isvalid(wordList[cur], endWord)) {
                vector<string> path;
                get_path(cur, previous, wordList, path);
                path.push_back(endWord);
                if (!res.empty() && path.size() > res.back().size()) {
                    break;
                }
                res.push_back(path);
            }
            for (int i = 0; i < wordList.size(); i++) {
                if (!visited[i] && isvalid(wordList[cur], wordList[i])) {
                    que.push(i);
                    visited[i] = true;
                    previous[i] = cur;
                }
            }
        }
        return res;
    }
};


int main() {
    string begin = "hit";
    string end = "cog";
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
    Solution s;
    vector<vector<string>> res = s.findLadders(begin, end, wordList);
    return 0;
}
