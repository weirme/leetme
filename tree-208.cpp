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

using namespace std;

const int INF = 0x7fffffff;

typedef struct Tnode {
    bool valid = false;
    Tnode * child[26];
    
    Tnode() {
        for (auto& node : child) {
            node = nullptr;
        }
    }
} Tnode;

class Trie {
private:
    Tnode * root;

public:
    Trie() {
        root = new Tnode;
    }
    
    void insert(string word) {
        Tnode * p = root;
        for (int i = 0; i < word.size(); i++) {
            if (p->child[word[i]-'a'] == nullptr) {
                p->child[word[i]-'a'] = new Tnode;
            }
            p = p->child[word[i]-'a'];
        }
        p->valid = true;
    }
    
    bool search(string word) {
        Tnode * p = root;
        for (int i = 0; i < word.size(); i++) {
            if (p->child[word[i]-'a'] == nullptr) return false;
            p = p->child[word[i]-'a'];
        }
        return p->valid;
    }
    
    bool startsWith(string prefix) {
        Tnode * p = root;
        for (int i = 0; i < prefix.size(); i++) {
            if (p->child[prefix[i]-'a'] == nullptr) return false;
            p = p->child[prefix[i]-'a'];
        }
        return true;
    }
};

int main() {
    Trie t;
    t.insert("apple");
    return 0;
}
