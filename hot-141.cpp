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
    bool hasCycle(ListNode *head) {
        ListNode* p = head;
        ListNode* q = head;
        while (p && p->next) {
            p = p->next->next;
            q = q->next;
            if (p == q) return true;
        }
        return false;
    }
};
