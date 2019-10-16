struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
 
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        int i = 1;
        ListNode *pre_head = new ListNode(0);
        pre_head->next = head;
        ListNode *pre = pre_head, *p = head, *t = nullptr;
        while (i < m) {
            pre = p;
            p = p->next;
            i++;
        }
        ListNode *rev_tail = p, *rev_p = p;
        ListNode *rev_head = new ListNode(0);
        rev_head->next = p;
        p = p->next;
        i++;
        while (i <= n) {
            t = p->next;
            p->next = rev_p;
            rev_head->next = p;
            rev_p = p;
            p = t;
            i++;
        }
        pre->next = rev_head->next;
        rev_tail->next = p;
        return pre_head->next;
    }
};
