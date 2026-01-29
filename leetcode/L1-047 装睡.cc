#include <bits/stdc++.h>

using namespace std;

#define ll long long
const ll MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    string s;
    int a, b;
    for (int i = 0; i < n; ++i) {
        cin >> s >> a >> b;
        if (a < 15 || a > 20 || b < 50 || b > 70) {
            cout << s << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}