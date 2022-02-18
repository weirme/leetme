#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <numeric>
#include "types.h"

using namespace std;

const int INF = 0x7fffffff;

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr) return head;
        ListNode* dummy = new ListNode(0);
        ListNode* r = dummy;
        ListNode* p = head;
        while (p && p->next) {
            r->next = p->next;
            r = p->next;
            p->next = p->next->next;
            if (p->next) p = p->next;
        }
        r->next = nullptr;
        p->next = dummy->next;
        return head;
    }
};
