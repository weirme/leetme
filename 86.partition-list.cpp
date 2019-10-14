struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};


class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (!head || !head->next) return head;
        ListNode *pre_head = new ListNode(0);
        pre_head->next = head;
        ListNode *pre = pre_head, *p = head;
        ListNode *t_head = new ListNode(0), *t = t_head;
        while (p) {
            if (p->val < x) {
                pre = p;
                p = p->next;
            }
            else {
                pre->next = p->next;
                t->next = p;
                t = p;
                p = pre->next;
            }
        }
        t->next = nullptr;
        pre->next = t_head->next;
        return pre_head->next;
    }
};


int main() {
    ListNode *head = new ListNode(1);
    ListNode *p = head;
    int nums[] = {4,3,2,5,2};
    for (int i = 0; i < 5; i++) {
        ListNode *t = new ListNode(nums[i]);
        p->next = t;
        p = p->next;
    }
    Solution s;
    ListNode *res = s.partition(head, 5);
    return 0;
}
