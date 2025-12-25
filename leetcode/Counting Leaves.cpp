#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    string val;
    vector<TreeNode*> children;
    TreeNode() : val(0), children(vector<TreeNode*>()) {}
    TreeNode(string x) : val(x), children(vector<TreeNode*>()) {}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    TreeNode* root = new TreeNode("01");
    if (n == 0) {
        cout << 0 << " " << 0;
        return 0;
    }
    
    return 0;
}