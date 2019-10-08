struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
 

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode *pre = head, *p = head->next;
        while (p) {
            if (p->val != pre->val) {
                pre->next = p;
                pre = p;
            }
            p = p->next;
        }
        pre->next = p;
        return head;
    }
};
