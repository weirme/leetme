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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode * dummy = new ListNode(0);
        dummy->next = head;
        ListNode * p = dummy;
        ListNode * q = dummy;
        while (n--) {
            p = p->next;
        }
        while (p->next) {
            p = p->next;
            q = q->next;
        }
        ListNode * t = q->next;
        q->next = t->next;
        delete t;
        head = dummy->next;
        delete dummy;
        return head;
    }
};
