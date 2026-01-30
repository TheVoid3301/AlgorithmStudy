#include <bits/stdc++.h>

using namespace std;

#define ll long long
const ll MOD = 1e9 + 7;

void solve() {
    char c;
    int n;
    cin >> c >> n;
    vector<vector<char>> v(n, vector<char>(n, ' '));
    vector<vector<char>> p(n, vector<char>(n, ' '));
    getchar();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            p[i][j] = getchar();
            if (p[i][j] !=  ' ') {
                p[i][j] = c;
            }
        }
        getchar();
    }
    v = p;
    for (int i = 0; i < n / 2; ++i) {
        for (int j = 0; j < n; ++j) {
            swap(v[i][j], v[n - i - 1][n - j - 1]);
        }
    }
    if (n % 2 == 1) {
        int l = n / 2;
        for (int i = 0; i < n / 2; ++i) {
            swap(v[l][i], v[l][n - i - 1]);
        }
    }
    if (p == v) {
        cout << "bu yong dao le" << endl;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << v[i][j];
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