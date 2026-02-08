#include <bits/stdc++.h>

using namespace std;

#define ll long long
const ll MOD = 1e9 + 7;
int n;
vector<vector<int>> m;

void solve() {
    cin >> n;
    m.resize(n + 1);
    int f;
    for (int i = 1; i < n + 1; ++i) {
        int t;
        cin >> t;
        if (t == -1) {
            f = i;
            continue;
        }
        m[t].push_back(i);
    }
    queue<int> q;
    vector<int> v;
    int res = 0;
    q.push(f);
    while (!q.empty()) {
        res++;
        v.clear();
        queue<int> t = q;
        while (!t.empty()) {
            v.push_back(t.front());
            t.pop();
        }
        int s = q.size();
        while (s--) {
            int k = q.front();
            q.pop();
            for (auto i : m[k]) {
                q.push(i);
            }
        }
    }
    cout << res << endl;
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); ++i) {
        if (i != v.size() - 1) {
            cout << v[i] << " ";
        } else {
            cout << v[i];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}