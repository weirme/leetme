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
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode * dummy = new ListNode(0);
        dummy->next = head;
        ListNode * r = nullptr;
        while (dummy->next != nullptr) {
            ListNode * pre_max = dummy;
            ListNode * p_max = dummy->next;
            ListNode * pre = dummy;
            ListNode * p = dummy->next;
            while (p != nullptr) {
                if (p->val > p_max->val) {
                    pre_max = pre;
                    p_max = p;
                }
                pre = p;
                p = p->next;
            }
            pre_max->next = p_max->next;
            p_max->next = r;
            r = p_max;
        }
        delete dummy;
        return r;
    }
};
