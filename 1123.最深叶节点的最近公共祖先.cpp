/*
 * @lc app=leetcode.cn id=1123 lang=cpp
 *
 * [1123] 最深叶节点的最近公共祖先
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
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if (!root) return nullptr;
        
        // 第一步：使用BFS找到所有最深叶节点
        queue<TreeNode*> q;
        q.push(root);
        unordered_set<TreeNode*> deepestLeaves;
        
        while (!q.empty()) {
            int levelSize = q.size();
            deepestLeaves.clear();  // 每次处理新的一层前清空
            
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();
                q.pop();
                
                if (!node->left && !node->right) {
                    deepestLeaves.insert(node);
                }
                
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        
        // 第二步：不断向上找父节点直到只剩一个节点
        while (deepestLeaves.size() > 1) {
            unordered_set<TreeNode*> parents;
            for (TreeNode* leaf : deepestLeaves) {
                // 需要从root开始找leaf的父节点
                TreeNode* parent = findParent(root, nullptr, leaf);
                if (parent) parents.insert(parent);
            }
            deepestLeaves = parents;
        }
        
        return *deepestLeaves.begin();
    }
    
private:
    // 辅助函数：找到目标节点的父节点
    TreeNode* findParent(TreeNode* root, TreeNode* parent, TreeNode* target) {
        if (!root) return nullptr;
        if (root == target) return parent;
        
        TreeNode* left = findParent(root->left, root, target);
        if (left) return left;
        
        return findParent(root->right, root, target);
    }
};


// class Solution {
// public:
//     TreeNode* lcaDeepestLeaves(TreeNode* root) {
//         return dfs(root).first;
//     }
    
// private:
//     pair<TreeNode*, int> dfs(TreeNode* node) {
//         if (!node) return {nullptr, 0};
        
//         auto left = dfs(node->left);
//         auto right = dfs(node->right);
        
//         if (left.second > right.second) {
//             return {left.first, left.second + 1};
//         }
//         if (right.second > left.second) {
//             return {right.first, right.second + 1};
//         }
//         return {node, left.second + 1};
//     }
// };
// @lc code=end

