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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* pre = head;
        ListNode* p = head->next;
        while (p) {
            if (p->val == pre->val) p = p->next;
            else {
                pre->next = p;
                pre = p;
                p = p->next;
            }
        }
        pre->next = nullptr;
        return head;
    }
};
