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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * res = new ListNode(0);
        ListNode * p = l1;
        ListNode * q = l2;
        ListNode * r = res;
        ListNode * t = nullptr;
        int carry = 0;
        while (l1 != nullptr && l2 != nullptr) {
            t = new ListNode((l1->val + l2->val + carry) % 10);
            carry = (l1->val + l2->val + carry) / 10;
            r->next = t;
            r = t;
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1 != nullptr) {
            t = new ListNode((l1->val + carry) % 10);
            carry = (l1->val + carry) / 10;
            r->next = t;
            r = t;
            l1 = l1->next;
        }
        while (l2 != nullptr) {
            t = new ListNode((l2->val + carry) % 10);
            carry = (l2->val + carry) / 10;
            r->next = t;
            r = t;
            l2 = l2->next;
        }
        if (carry != 0) {
            t = new ListNode(carry);
            r->next = t;
        }
        t = res->next;
        delete res;
        return t;
    }
};
