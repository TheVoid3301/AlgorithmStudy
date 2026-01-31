#include <bits/stdc++.h>

using namespace std;

#define ll long long
const ll MOD = 1e9 + 7;

void solve() {
    string s;
    getline(cin, s);
    int n = 0, k = 0, p = 0;
    bool f = false;
    while (s != ".") {
        n++;
        if (s.find("chi1 huo3 guo1") != string::npos) {
            p++;
            if (!f) {
                f = true;
                k = n;
            }
        }
        getline(cin, s);
    }
    cout << n << endl;
    if (f) {
        cout << k << " " << p;
    } else {
        cout << "-_-#";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}