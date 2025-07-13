/*
 * @lc app=leetcode.cn id=1290 lang=cpp
 *
 * [1290] 二进制链表转整数
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
    int getDecimalValue(ListNode* head) {
        ListNode* h = head;
        int n = 0;
        while (h) {
            ++n;
            h = h->next;
        }
        int res = 0;
        while (head) {
            res += head->val * (int)(pow(2, n - 1));
            --n;
            head = head->next;
        }
        return res;
    }
};
// @lc code=end

