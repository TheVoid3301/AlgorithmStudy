#include <bits/stdc++.h>

using namespace std;

#define ll long long
const ll MOD = 1e9 + 7;

void solve() {
    string s;
    cin >> s;
    int start = 0;
    string m = "", d = "", y = "";
    int t = s.find('-', start);
    m += s[t - 2];
    m += s[t - 1];
    start = t + 1;
    t = s.find('-', start);
    d += s[t - 2];
    d += s[t - 1];
    y += s[s.size() - 4];
    y += s[s.size() - 3];
    y += s[s.size() - 2];
    y += s[s.size() - 1];
    cout << y + "-" + m + "-" + d;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}