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
#include "types.h"

using namespace std;

const int INF = 0x3f3f3f3f;

class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        if (head == nullptr)
            return head;
        ListNode * p = head;
        ListNode * q = head;
        while (k-- && p != nullptr) {
            p = p->next;
        }
        if (k > 0) return nullptr;
        while (p != nullptr) {
            p = p->next;
            q = q->next;
        }
        return q;
    }
};
