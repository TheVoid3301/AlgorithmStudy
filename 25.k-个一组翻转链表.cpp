/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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
    void reverse_listnode(ListNode* &head, int s, int e)
    {
        ListNode *p = head, *cur, *end, *pre, *endnext, *headpre;
        for(int i = 0; i <= e; ++i)
        {
            if(i == s)
            {
                cur = p;
            }
            if(i == s - 1)
            {
                headpre = p;
            }
            if(i == e)
            {
                end = p;
            }
            p = p -> next;
        }
        endnext = end -> next;
        pre = endnext;
        while(cur != endnext)
        {
            ListNode *next = cur -> next;
            cur -> next = pre;
            pre = cur;
            cur = next;
        }
        if(s != 0)
        {
            headpre -> next = pre;
        }
        if(s == 0)
        {
            head = pre;
        }
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *p = head;
        int left = 0, right = 0;
        vector<pair<int, int>> re;
        while(p != nullptr)
        {
            if(right - left == k - 1)
            {
                re.push_back({left, right});
                left = right + 1;
            }
            ++right;
            p = p -> next;
        }
        for(auto i : re)
        {
            reverse_listnode(head, i.first, i.second);
        }
        return head;
    }
};
// @lc code=end

