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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* pre = dummy;
        ListNode* p = head;
        ListNode* q = nullptr;
        ListNode* t = nullptr;
        int i = 1;
        while (i < left) {
            pre = p;
            p = p->next;
            i++;
        }
        q = p;
        while (i <= right) {
            t = p->next;
            p->next = pre->next;
            pre->next = p;
            p = t;
            i++;
        }
        q->next = p;
        return dummy->next;
    }
};
