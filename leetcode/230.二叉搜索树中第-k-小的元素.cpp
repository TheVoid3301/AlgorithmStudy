/*
 * @lc app=leetcode.cn id=230 lang=cpp
 *
 * [230] 二叉搜索树中第 K 小的元素
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// 略微简单，只需要加入中序遍历即可
class Solution {
public:
    vector<int> v;
    void mid(TreeNode* root)
    {
        if(root)
        {
            mid(root -> left);
            v.push_back(root -> val);
            mid(root -> right);
        }
    }
    int kthSmallest(TreeNode* root, int k)
    {
        mid(root);
        return v[k - 1];
    }
};
// @lc code=end

