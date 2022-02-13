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

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* pre = head;
        Node* p = nullptr;
        while (pre) {
            p = pre->next;
            Node* t = new Node(pre->val);
            t->next = p;
            pre->next = t;
            pre = p;
        }
        pre = head;
        while (pre) {
            p = pre->next;
            if (pre->random != nullptr)
                p->random = pre->random->next;
            pre = p->next;
        }
        Node* dummy = new Node(0);
        pre = head;
        Node* r = dummy;
        while (pre) {
            p = pre->next;
            pre->next = p->next;
            pre = pre->next;
            r->next = p;
            r = p;
        }
        r->next = nullptr;
        return dummy->next;
    }
};
