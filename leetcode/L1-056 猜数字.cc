#include <bits/stdc++.h>

using namespace std;

#define ll long long
const ll MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    map<string, int> m;
    string s;
    int k, t = 0;
    for (int i = 0; i < n; ++i) {
        cin >> s >> k;
        m[s] = k;
        t += k;
    }
    double p = (double)t / 2 / n;
    string pre = (*m.begin()).first;
    double j = abs((*m.begin()).second - p);
    for (auto i : m) {
        if (abs(i.second - p) < j) {
            j = abs(i.second - p);
            pre = i.first;
        }
    }
    cout << (int)p<< " " << pre;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}