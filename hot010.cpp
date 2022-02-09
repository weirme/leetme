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

typedef struct Node {
    unordered_map<char, Node*> next;
} Node;

typedef struct Block {
    Node * in;
    Node * out;
    
    Block(char c, char pre=0) {
        if (c == '*') {
            in = new Node;
            Node * mid = new Node;
            out = new Node;
            in->next[pre] = mid;
            in->next[0] = out;
            mid->next[pre] = mid;
            mid->next[0] = out;
        }
        else {
            in = new Node;
            out = new Node;
            in->next[c] = out;
        }
    }
} Block;

class Solution {
private:
    Node * state_mach(string& s) {
        int p = 0, q = 1;
        Node * in = new Node;
        Node * r = in;
        while (q < s.size()) {
            if (s[q] == '*') {
                Block blk(s[q], s[p]);
                r->next[0] = blk.in;
                r = blk.out;
                p = q+1;
                q = p+1;
            }
            else {
                Block blk(s[p]);
                r->next[0] = blk.in;
                r = blk.out;
                p++;
                q++;
            }
        }
        if (p < s.size()) {
            Block blk(s[p]);
            r->next[0] = blk.in;
        }
        return in;
    }
    
    bool traverse(string& s, string::iterator it, Node * q) {
        if (it == s.end()) {
            while (q->next.find(0) != q->next.end()) {
                q = q->next[0];
            }
            return q->next.empty();
        }
        if (q->next.find(*it) != q->next.end() && traverse(s, it+1, q->next[*it]))
            return true;
        if (q->next.find('.') != q->next.end() && traverse(s, it+1, q->next['.']))
            return true;
        if (q->next.find(0) != q->next.end() && traverse(s, it, q->next[0]))
            return true;
        return false;
    }
    
public:
    bool isMatch(string s, string p) {
        Node * q = state_mach(p);
        auto it = s.begin();
        return traverse(s, it, q);
    }
};

int main() {
    string s = "ab";
    string p = ".*";
    Solution sol;
    bool res = sol.isMatch(s, p);
    return 0;
}
