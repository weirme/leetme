struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};


class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *p_head = new ListNode(0);
        p_head->next = head;
        ListNode *pre = p_head, *p = pre->next, *q = nullptr;
        while (p && p->next) {
            q = p->next;
            p->next = q->next;
            pre->next = q;
            q->next = p;
            pre = p;
            p = pre->next;
        }
        return p_head->next;
    }
};