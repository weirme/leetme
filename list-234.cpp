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
    bool isPalindrome(ListNode* head) {
        ListNode * p = head;
        ListNode * q = head;
        int n = 0;
        while (p && p->next) {
            p = p->next->next;
            q = q->next;
            n++;
        }
        ListNode * r = new ListNode(0);
        while (q) {
            ListNode * t = q->next;
            q->next = r->next;
            r->next = q;
            q = t;
        }
        p = head;
        q = r->next;
        while (n--) {
            if (p->val != q->val) return false;
            p = p->next;
            q = q->next;
        }
        delete r;
        return true;
    }
};
