struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
 

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* pre = new ListNode(0xffff);
        pre->next = head;
        head = pre;
        ListNode *p = head, *q = head->next;
        bool flag = false;
        while (q) {
            if (p->val != q->val) {
                if (flag) {
                    pre->next = q;
                    flag = false;
                }
                else pre = p;
                p = q;
                q = q->next;
            }
            else {
                flag = true;
                p = q;
                q = q->next;
            }
        }
        if (flag) pre->next = q;
        return head->next;
    }
};
