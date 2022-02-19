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

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* pre = dummy;
        ListNode* p = head;
        ListNode* q = nullptr;
        while (p) {
            q = p->next;
            if (q != nullptr && p->val == q->val) {
                while (q && p->val == q->val) q = q->next;
                pre->next = q;
                p = q;
            }
            else {
                pre = p;
                p = q;
            }
        }
        return dummy->next;
    }
};
