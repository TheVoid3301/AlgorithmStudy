#include <bits/stdc++.h>

using namespace std;

#define ll long long
const ll MOD = 1e9 + 7;

void solve() {
    int n, m;
    cin >> n >> m;
    string s;
    for (int i = 0; i < m; ++i) {
        cin >> s;
        int t = 0;
        if (s[0] == 'y') {
            t = 0;
        } else {
            t = 1;
        }
        for (int j = 1; j < n; ++j) {
            if (s[j] == 'y') {
                t *= 2;
            } else {
                t = t * 2 + 1;
            }
        }
        cout << t + 1 << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}