#include <bits/stdc++.h>

using namespace std;

#define ll long long
const ll MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    getchar();
    string s;
    for (int i = 0; i < n; ++i) {
        getline(cin, s);
        int k = s.find(",");
        if (k < 3 || s.size() - 4 < 3) {
            cout << "Skipped" << endl;
            continue;
        }
        if (s.substr(k - 3, 3) == "ong" && s.substr(s.size() - 4, 3) == "ong") {
            int t = s.rfind(" ");
            t = s.rfind(" ", t - 1);
            t = s.rfind(" ", t - 1);
            cout << s.substr(0, t) + " qiao ben zhong." << endl;
        } else {
            cout << "Skipped" << endl;
        }
    }
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);

    solve();

    return 0;
}