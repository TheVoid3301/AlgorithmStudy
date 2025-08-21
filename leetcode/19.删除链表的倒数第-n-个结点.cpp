/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int l = 0;
        ListNode *p = head, *q = head;
        while(head)
        {
            l++;
            head = head -> next;
        }
        if(l == 1)
        {
            return nullptr;
        }
        l = l - n;
        if(l == 0)
        {
            return p -> next;
        }
        for(l; l > 1; --l)
        {
            q = q -> next;
        }
        ListNode *m = q -> next;
        q -> next = m -> next;
        delete(m);
        return p;
    }
};
// @lc code=end

