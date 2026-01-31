#include <bits/stdc++.h>

using namespace std;

#define ll long long
const ll MOD = 1e9 + 7;

void solve() {
    int n;
    double res = 0.0, t;
    cin >> n;
    cout << fixed << setprecision(2);
    for (int i = 0; i < n; ++i) {
        cin >> t;
        res += 1 / t;
    }
    cout << 1 / (res / n);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}