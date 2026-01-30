#include <bits/stdc++.h>

using namespace std;

#define ll long long
const ll MOD = 1e9 + 7;

void solve() {
    double w, h;
    cin >> w >> h;
    if (w / h / h > 25) {
        cout << fixed << setprecision(1) << w / h / h << endl;
        cout << "PANG";
    } else {
        cout << fixed << setprecision(1) << w / h / h << endl;
        cout << "Hai Xing";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}