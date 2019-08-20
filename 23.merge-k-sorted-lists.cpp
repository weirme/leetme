/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
 *
 * https://leetcode.com/problems/merge-k-sorted-lists/description/
 *
 * algorithms
 * Hard (33.53%)
 * Total Accepted:    361.4K
 * Total Submissions: 1.1M
 * Testcase Example:  '[[1,4,5],[1,3,4],[2,6]]'
 *
 * Merge k sorted linked lists and return it as one sorted list. Analyze and
 * describe its complexity.
 * 
 * Example:
 * 
 * 
 * Input:
 * [
 * 1->4->5,
 * 1->3->4,
 * 2->6
 * ]
 * Output: 1->1->2->3->4->4->5->6
 * 
 * 
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

typedef struct ListNode ListNode;

ListNode* merge(ListNode* lists1, ListNode* lists2) {
    ListNode *res = nullptr;
    ListNode *p = lists1, *q = lists2, *r = res;
    while (p && q && p->val && q->val) {
        if (p->val < q->val) {
            ListNode *t = new ListNode(p->val);
            r->next = t;
            r = t;
            p = p->next;
        } else {
            ListNode *t = new ListNode(q->val);
            r->next = t;
            r = t;
            q = q->next;
        }
    }
    while (p && p->val) {
        ListNode *t = new ListNode(p->val);
        r->next = t;
        r = t;
        p = p->next;
    }
    while (q && q->val) {
        ListNode *t = new ListNode(q->val);
        r->next = t;
        r = t;
        q = q->next;
    }
    return res;
}

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int size = lists.size();
        if (size == 0) return nullptr;
        if (size == 1) return lists[0];
        else {
            int s = size/2;
            vector<ListNode*> lists1(lists.begin(), lists.begin()+s);
            vector<ListNode*> lists2(lists.begin()+s, lists1.end());
            return merge(mergeKLists(lists1), mergeKLists(lists2));
        }
    }
};


