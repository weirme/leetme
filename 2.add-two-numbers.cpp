struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int flag = 0;
        int sum = 0;
        ListNode* res = new ListNode(0);
        ListNode *p = l1, *q = l2, *r = res;
        while (p && q) {
            sum = p->val + q->val + flag;
            ListNode* t = new ListNode(sum % 10);
            flag = sum / 10;
            r->next = t;
            r = t;
            p = p->next;
            q = q->next;
        }
        while (p) {
            sum = p->val + flag;
            ListNode* t = new ListNode(sum % 10);
            flag = sum / 10;
            r->next = t;
            r = t;
            p = p->next;
        }
        while (q) {
            sum = q->val + flag;
            ListNode* t = new ListNode(sum % 10);
            flag = sum / 10;
            r->next = t;
            r = t;
            q = q->next;
        }
        if (flag) {
            ListNode* t = new ListNode(1);
            r->next = t;
        }
        return res->next;
    }
};