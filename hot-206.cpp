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
    ListNode* reverseList(ListNode* head) {
        ListNode * pre = nullptr;
        ListNode * p = head;
        ListNode * q = nullptr;
        while (p) {
            q = p->next;
            p->next = pre;
            pre = p;
            p = q;
        }
        return pre;
    }
};
