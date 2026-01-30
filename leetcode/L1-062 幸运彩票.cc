#include <bits/stdc++.h>

using namespace std;

#define ll long long
const ll MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    string s;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        if (s[0] + s[1] + s[2] == s[3] + s[4] + s[5]) {
            cout << "You are lucky!" << endl;
        } else {
            cout << "Wish you good luck." << endl;
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