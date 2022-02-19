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
private:
    ListNode* reverse(ListNode* head, int k) {
        ListNode* h = nullptr;
        ListNode* p = head;
        ListNode* q = nullptr;
        while (k--) {
            q = p->next;
            p->next = h;
            h = p;
            p = q;
        }
        return h;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* h = head;
        ListNode* p = head;
        ListNode* q = head;
        ListNode* pre = nullptr;
        while (q) {
            int i = 0;
            while (q && i < k) {
                q = q->next;
                i++;
            }
            if (i < k) break;
            ListNode* hi = reverse(p, k);
            if (pre == nullptr) h = hi;
            else pre->next = hi;
            pre = p;
            p = q;
        }
        pre->next = p;
        return h;
    }
};
