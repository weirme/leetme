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
    ListNode* reverse(ListNode* head) {
        ListNode* h = nullptr;
        ListNode* p = head;
        ListNode* t = nullptr;
        while (p) {
            t = p->next;
            p->next = h;
            h = p;
            p = t;
        }
        return h;
    }
    
public:
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return true;
        ListNode* p = head;
        ListNode* q = head->next;
        while (q && q->next) {
            p = p->next;
            q = q->next->next;
        }
        ListNode* mid = reverse(p->next);
        p = head;
        q = mid;
        while (p && q) {
            if (p->val != q->val) return false;
            p = p->next;
            q = q->next;
        }
        return true;
    }
};
