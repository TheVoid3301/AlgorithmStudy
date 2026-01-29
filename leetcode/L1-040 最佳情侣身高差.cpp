#include <bits/stdc++.h>

using namespace std;

#define ll long long
const ll MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    char s;
    double h;
    for (int i = 0; i < n; ++i) {
        cin >> s >> h;
        if (s == 'F') {
            cout << fixed << setprecision(2) << h * 1.09;
        } else {
            cout << fixed << setprecision(2) << h / 1.09;
        }
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}