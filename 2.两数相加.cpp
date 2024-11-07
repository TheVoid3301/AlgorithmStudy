/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *q = new ListNode();
        ListNode *p = q;
        int c = 0;
        while(l1 && l2)
        {
            if(l1 -> val + l2 -> val + c >= 10)
            {
                p -> val = l1 -> val + l2 -> val - 10 + c;
                c = 1;
            }
            else
            {
                p -> val = l1 -> val + l2 -> val + c;
                c = 0;
            }
            if(l1 -> next || l2 -> next)
            {
                p -> next = new ListNode();
                p = p -> next;
            }
            l1 = l1 -> next;
            l2 = l2 -> next;
        }
        while(l1)
        {
            if(l1 -> val + c >= 10)
            {
                p -> val = l1 -> val + c - 10;
                c = 1;
            }
            else
            {
                p -> val = l1 -> val + c;
                c = 0;
            }
            if(l1 -> next)
            {
                l1 = l1 -> next;
                p -> next = new ListNode();
                p = p -> next;
            }
            else
            {
                break;
            }
        }
        while(l2)
        {
            if(l2 -> val + c >= 10)
            {
                p -> val = l2 -> val + c - 10;
                c = 1;
            }
            else
            {
                p -> val = l2 -> val + c;
                c = 0;
            }
            if(l2 -> next)
            {
                l2 = l2 -> next;
                p -> next = new ListNode();
                p = p -> next;
            }
            else
            {
                break;
            }
        }
        if(c)
        {
            p -> next = new ListNode(c);
        }
        return q;
    }
};
// @lc code=end

