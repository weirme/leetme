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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr)
            return l2;
        if (l2 == nullptr)
            return l1;
        ListNode * head = new ListNode(0);
        ListNode * p = head;
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                p->next = l1;
                l1 = l1->next;
                p = p->next;
            }
            else {
                p->next = l2;
                l2 = l2->next;
                p = p->next;
            }
        }
        while (l1 != nullptr) {
            p->next = l1;
            l1 = l1->next;
            p = p->next;
        }
        while (l2 != nullptr) {
            p->next = l2;
            l2 = l2->next;
            p = p->next;
        }
        return head->next;
    }
};
