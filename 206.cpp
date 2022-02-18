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
    ListNode* solve(ListNode* head, ListNode* &pre) {
        if (head == nullptr) return head;
        if (head->next == nullptr) {
            pre = head;
            return head;
        }
        ListNode* p = head;
        ListNode* h = solve(p->next, pre);
        pre->next = p;
        p->next = nullptr;
        pre = p;
        return h;
    }
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = nullptr;
        return solve(head, pre);
    }
};
