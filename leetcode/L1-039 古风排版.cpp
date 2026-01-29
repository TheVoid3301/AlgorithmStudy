#include <bits/stdc++.h>

using namespace std;

#define ll long long
const ll MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    string s;
    getchar();
    getline(cin, s);
    int c = ceil((float)s.size() / n);
    vector<vector<char>> res(n, vector<char>(c, ' '));
    int k = 0;
    for (int j = c - 1; j >= 0; --j) {
        for (int i = 0; i < n; ++i) {
            if (k >= s.size()) {
                continue;
            }
            res[i][j] = s[k++];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < c; ++j) {
            cout << res[i][j];
        }
        cout << endl;
    }
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);

    solve();

    return 0;
}