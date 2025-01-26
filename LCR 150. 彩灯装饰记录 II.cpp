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
    vector<vector<int>> decorateRecord(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;
        int n;
        vector<int> p;
        if (!root) {
            return {};
        }
        q.push(root);
        while (!q.empty()) {
            n = q.size();
            while (n) {
                p.push_back(q.front() -> val);
                if (q.front() -> left) {
                    q.push(q.front() -> left);
                }
                if (q.front() -> right) {
                    q.push(q.front() -> right);
                }
                q.pop();
                --n;
            }
            res.push_back(p);
            p.clear();
        }
        return res;
    }
};