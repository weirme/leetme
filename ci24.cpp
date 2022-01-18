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
#include <algorithm>
#include "types.h"

using namespace std;

const int INF = 0x3f3f3f3f;

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode * res = nullptr;
        ListNode * t = nullptr;
        while (head != nullptr) {
            t = head;
            head = head->next;
            t->next = res;
            res = t;
        }
        return res;
    }
};
