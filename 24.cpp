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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* pre = dummy;
        ListNode* p = head;
        ListNode* q = nullptr;
        while (p && p->next) {
            q = p->next->next;
            pre->next = p->next;
            p->next->next = p;
            p->next = q;
            pre = p;
            p = q;
        }
        return dummy->next;
    }
};
