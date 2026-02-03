#include <bits/stdc++.h>

using namespace std;

#define ll long long
const ll MOD = 1e9 + 7;
int n;
vector<int> pre(35, 0);
vector<int> in(35, 0);
string res("");

struct Tree {
    int data;
    struct Tree* l, * r;
    Tree(int x) {
        data = x;
        l = nullptr;
        r = nullptr;
    }
};

Tree* buildTree(int prel, int prer, int inl, int inr) {
    if (prel > prer || inl > inr) {
        return nullptr;
    }
    Tree* root = new Tree(pre[prel]);
    int t = inl;
    for (int i = inl; i <= inr; ++i) {
        if (in[i] == pre[prel]) {
            t = i;
            break;
        }
    }
    root->l = buildTree(prel + 1, prel + t - inl, inl, t - 1);
    root->r = buildTree(prel + t - inl + 1, prer, t + 1, inr);
    return root;
}

void re(Tree* root) {
    if (!root) {
        return;
    }
    swap(root->l, root->r);
    re(root->l);
    re(root->r);
}

void cenxu(Tree* root) {
    queue<Tree*> q;
    q.push(root);
    while (!q.empty()) {
        int s = q.size();
        while (s) {
            Tree* t = q.front();
            q.pop();
            res += to_string(t->data);
            res += " ";
            if (t->l) {
                q.push(t->l);
            }
            if (t->r) {
                q.push(t->r);
            }
            s--;
        }
    }
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> in[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> pre[i];
    }
    Tree* root = buildTree(0, n - 1, 0, n - 1);
    re(root);
    cenxu(root);
    res.pop_back();
    cout << res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}