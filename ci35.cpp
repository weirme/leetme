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

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

using namespace std;

const int INF = 0x3f3f3f3f;

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr)
            return nullptr;
        Node * p = head;
        Node * q = nullptr;
        Node * t = nullptr;
        while (p != nullptr) {
            t = new Node(p->val);
            t->next = p->next;
            p->next = t;
            p = t->next;
        }
        p = head;
        while (p != nullptr) {
            q = p->next;
            if (p->random != nullptr)
                q->random = p->random->next;
            p = q->next;
        }
        Node *cp_head = new Node(0);
        p = head;
        q = cp_head;
        while (p != nullptr) {
            t = p->next;
            p->next = t->next;
            p = t->next;
            t->next = q->next;
            q->next = t;
            q = t;
        }
        return cp_head->next;
    }
};
