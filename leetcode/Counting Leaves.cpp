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
    vector<int> tree(n + 1, -1);
    if (n == 0) {
        cout << 0 << " " << 0;
        return 0;
    }
    for (int i = 0; i < m; ++i) {
        int id;
        int childnum;
        cin >> id >> childnum;
        for (int j = 0; j < childnum; ++j) {
            int childid;
            cin >> childid;
            tree[childid] = id;
        }
    }
    queue<int> q;
    q.push(1);
    int maxDepth = 0;
    int leafCount = 0;
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            int node = q.front();
            q.pop();
            bool isLeaf = true;
            for (int j = 1; j <= n; ++j) {
                if (tree[j] == node) {
                    q.push(j);
                    isLeaf = false;
                }
            }
            if (isLeaf) {
                leafCount++;
            }
        }
        if (q.empty()) {
            cout << leafCount;
            break;
        }
        cout << leafCount << " ";
        leafCount = 0;
    }
    return 0;
}