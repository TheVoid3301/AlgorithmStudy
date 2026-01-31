#include <bits/stdc++.h>

using namespace std;

#define ll long long
const ll MOD = 1e9 + 7;

void solve() {
    vector<int> x(24);
    for (int i = 0; i < 24; ++i) {
        cin >> x[i];
    }
    int t;
    cin >> t;
    while (t >= 0 && t <= 23) {
        if (x[t] > 50) {
            cout << x[t] << " Yes" << endl;
        } else {
            cout << x[t] << " No" << endl;
        }
        cin >> t;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}