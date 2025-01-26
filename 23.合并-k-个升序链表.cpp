/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并 K 个升序链表
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
    ListNode* merge(ListNode* a, ListNode* b) {
        ListNode* p, * q;
        if (!a) {
            return b;
        } else if (!b) {
            return a;
        }
        if (a -> val < b -> val) {
            p = a;
            q = b;
        } else {
            p = b;
            q = a;
        }
        ListNode* head = p;
        int i = 0;
        while (p && q) {
            ListNode* prep = p;
            while (q && p && p -> val <= q -> val) {
                prep = p;
                p = p -> next;
            }
            if (q) {
                prep -> next = q;
            } else {
                break;
            }
            ListNode* preq = q;
            while (p && q && q -> val <= p -> val) {
                preq = q;
                q = q -> next;
            }
            if (p) {
                preq -> next = p;
            } else {
                break;
            }
        }
        return head;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* res = nullptr;
        for (int i = lists.size() - 1; i >= 0; --i) {
            res = merge(lists[i], res);
        }
        return res;
    }
};
// @lc code=end

