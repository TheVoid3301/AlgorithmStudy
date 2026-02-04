#include <bits/stdc++.h>

using namespace std;

#define ll long long
const ll MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> m(n);
    for (int i = 0; i < n; ++i) {
        cin >> m[i];
    }
    sort(m.begin(), m.end());
    int a = n / 2;
    int b = n - a;
    cout << "Outgoing #: " << b << endl;
    cout << "Introverted #: " << a << endl;
    cout << "Diff = " << abs(accumulate(m.begin(), m.begin() + a, 0L) - accumulate(m.begin() + a, m.end(), 0L));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}