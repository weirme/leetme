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
    vector<int> reversePrint(ListNode* head) {
        int n = 0;
        ListNode* p = head;
        while (p) {
            n++;
            p = p->next;
        }
        vector<int> res(n);
        if (n > 0) {
            p = head;
            auto it = res.end() - 1;
            while (p) {
                *it-- = p->val;
                p = p->next;
            }
        }
        return res;
    }
};
