/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool hasChild(TreeNode* root, TreeNode* p)
    {
        if(root == nullptr)
        {
            return false;
        }
        if(root == p)
        {
            return true;
        }
        return hasChild(root -> left, p) || hasChild(root -> right, p);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        queue<TreeNode*> qu;
        TreeNode* ans = nullptr;
        qu.push(root);
        while(!qu.empty())
        {
            TreeNode* l = qu.front();
            qu.pop();
            if(hasChild(l, p) && hasChild(l, q))
            {
                ans = l; 
            }
            if(l -> left != nullptr)
            {
                qu.push(l -> left);
            }
            if(l -> right != nullptr)
            {
                qu.push(l -> right);
            }
        }
        return ans;
    }
};
// @lc code=end

