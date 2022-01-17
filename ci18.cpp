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
    ListNode* deleteNode(ListNode* head, int val) {
        if (head == nullptr)
            return head;
        if (head->val == val)
            return head->next;
        ListNode * p = head;
        ListNode * q = head->next;
        while (q != nullptr) {
            if (q->val == val) {
                p->next = q->next;
                q = p->next;
            }
            else {
                p = q;
                q = p->next;
            }
        }
        return head;
    }
};
