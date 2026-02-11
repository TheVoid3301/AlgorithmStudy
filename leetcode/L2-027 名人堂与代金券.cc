#include <bits/stdc++.h>

using namespace std;

#define ll long long
const ll MOD = 1e9 + 7;

void solve() {
    int n, g, k;
    map<int, vector<string>> m;
    string s;
    int t;
    cin >> n >> g >> k;
    int res = 0;
    while (n--) {
        cin >> s >> t;
        m[t].push_back(s);
        if (t >= 60 && t < g) {
            res += 20;
        } else if (t >= g) {
            res += 50;
        }
    }
    cout << res << endl;
    int p = 1;
    for (auto i = m.rbegin(); i != m.rend(); ++i) {
        if (k <= 0) {
            break;
        }
        sort(i->second.begin(), i->second.end());
        for (auto j : i->second) {
            cout << p << " " << j << " " << i->first << endl;
        }
        p += i->second.size();
        k -= i->second.size();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}