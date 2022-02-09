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

typedef
struct Node {
    int key;
    int val;
    Node* prev;
    Node* next;
    
    Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
} Node;

class LRUCache {
private:
    size_t capacity;
    size_t n;
    unordered_map<int, Node*> mp;
    Node * head;
    
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        n = 0;
        head = nullptr;
    }
    
    int get(int key) {
        auto it = mp.find(key);
        if (it == mp.end()) return -1;
        Node * p = it->second;
        if (p != head) {
            p->prev->next = p->next;
            p->next->prev = p->prev;
            p->prev = head->prev;
            p->next = head;
            head->prev->next = p;
            head->prev = p;
            head = p;
        }
        return head->val;
    }
    
    void put(int key, int value) {
        auto it = mp.find(key);
        if (it != mp.end()) {
            Node * p = it->second;
            p->val = value;
            if (p != head) {
                p->prev->next = p->next;
                p->next->prev = p->prev;
                p->prev = head->prev;
                p->next = head;
                head->prev->next = p;
                head->prev = p;
                head = p;
            }
            return;
        }
        if (n == capacity) {
            Node * p = head->prev;
            mp.erase(p->key);
            if (p == head) head = nullptr;
            else {
                p->prev->next = head;
                head->prev = p->prev;
            }
            n--;
        }
        Node * p = new Node(key, value);
        mp[key] = p;
        if (head == nullptr) {
            p->prev = p;
            p->next = p;
            head = p;
        }
        else {
            p->prev = head->prev;
            p->next = head;
            head->prev->next = p;
            head->prev = p;
            head = p;
        }
        n++;
    }
};
