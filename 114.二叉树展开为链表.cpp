/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
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
class Solution {
public:
    void pre(vector<int> &res, TreeNode* root)
    {
        if(!root)
        {
            return ;
        }
        res.push_back(root -> val);
        pre(res, root -> left);
        pre(res, root -> right);
    }
    void flatten(TreeNode* root) 
    {
        if (!root)
        {
            return ;
        }
        vector<int> res;
        pre(res, root);
        TreeNode *current = root;
        for (size_t i = 1; i < res.size(); ++i) { // 从索引1开始，因为root已经是第一个元素
            current->right = new TreeNode(res[i]);
            current->left = nullptr;
            current = current->right;
        }
        // 确保最后一个节点的左右子节点都为nullptr
        current->left = current->right = nullptr;
    }
};
// @lc code=end

