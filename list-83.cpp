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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode * dummy = new ListNode(0);
        dummy->next = head;
        ListNode * p = dummy;
        ListNode * q = head;
        while (q) {
            if (q->next && q->val == q->next->val) {
                ListNode * t = q->next;
                delete q;
                q = t;
            }
            else {
                p->next = q;
                p = q;
                q = q->next;
            }
        }
        p->next = q;
        head = dummy->next;
        delete dummy;
        return head;
    }
};
