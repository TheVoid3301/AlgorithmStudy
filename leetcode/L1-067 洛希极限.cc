#include <bits/stdc++.h>

using namespace std;

#define ll long long
const ll MOD = 1e9 + 7;

void solve() {
    double p, r, n;
    int s;
    cin >> p >> s >> r;
    cout << fixed << setprecision(2);
    if (s == 0) {
        n = 2.455;
    } else {
        n = 1.26;
    }
    if (p * n >= r) {
        cout << p * n << " T_T";
    } else {
        cout << p * n << " ^_^";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}