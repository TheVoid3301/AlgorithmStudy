#include <bits/stdc++.h>

using namespace std;

#define ll long long
const ll MOD = 1e9 + 7;

void solve() {
    int k;
    cin >> k;
    string s;
    int t = 0;
    while (cin >> s && s != "End") {
        if (t == k) {
            t = 0;
            cout << s << endl;
            continue;
        }
        if (s == "ChuiZi") {
            cout << "Bu" << endl;
        } else if (s == "JianDao") {
            cout << "ChuiZi" << endl;
        } else {
            cout << "JianDao" << endl;
        }
        ++t;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}