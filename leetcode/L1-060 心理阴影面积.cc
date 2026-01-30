#include <bits/stdc++.h>

using namespace std;

#define ll long long
const ll MOD = 1e9 + 7;

void solve() {
    int x, y;
    cin >> x >> y;
    cout << 5000 - x * y / 2 - (100 - x) * (100 - y) / 2 - y * (100 - x);
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}