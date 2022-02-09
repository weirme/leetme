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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode * dummy = new ListNode(0);
        ListNode * p = list1;
        ListNode * q = list2;
        ListNode * r = dummy;
        while (p && q) {
            if (p->val < q->val) {
                r->next = p;
                r = p;
                p = p->next;
            }
            else {
                r->next = q;
                r = q;
                q = q->next;
            }
        }
        if (p) r->next = p;
        else r->next = q;
        return dummy->next;
    }
};
