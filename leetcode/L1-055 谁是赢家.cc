#include <bits/stdc++.h>

using namespace std;

#define ll long long
const ll MOD = 1e9 + 7;

void solve() {
    int p1, p2;
    int k = 0;
    cin >> p1 >> p2;
    for (int i = 0; i < 3; ++i) {
        int l;
        cin >> l;
        if (l == 0) {
            k++;
        }
    }
    if (p1 > p2 && k >= 1 || p1 < p2 && k == 3) {
        cout << "The winner is a: " << p1 << " + " << k;
    } else {
        cout << "The winner is b: " << p2 << " + " << 3 - k;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}