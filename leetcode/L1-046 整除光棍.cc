#include <bits/stdc++.h>

using namespace std;

#define ll long long
const ll MOD = 1e9 + 7;

void solve() {
    unsigned int x;
    cin >> x;
    unsigned long long p = 1;
    unsigned int n = 1;
    while (p < x) {
        p = p * 10 + 1;
        ++n;
    }
    unsigned long long res = p / x;
    cout << res;
    unsigned long long m = p % x;
    while (m != 0) {
        m = m * 10 + 1;
        cout << m / x;
        m = m % x;
        ++n;
    }
    cout << " " << n;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}