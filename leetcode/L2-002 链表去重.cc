#include <bits/stdc++.h>

using namespace std;

#define ll long long
const ll MOD = 1e9 + 7;

vector<pair<int, int>> m(100005, pair<int, int>(0, -1));

void solve() {
    int sp, n, t, p, q;
    cin >> sp >> n;
    map<int, bool> k;
    for (int i = 0; i < n; ++i) {
        cin >> t >> p >> q;
        m[t].first = p;
        m[t].second = q;
    }
    map<int, int> has;
    vector<pair<int, int>> diyi;
    vector<pair<int, int>> dier;
    
    while (sp != -1) {
        if (has.contains(abs(m[sp].first))) {
            dier.push_back(make_pair(sp, m[sp].first));
        } else {
            diyi.push_back(make_pair(sp, m[sp].first));
            has[abs(m[sp].first)] = 1;
        }
        sp = m[sp].second;
    }

    for (int i = 0; i < diyi.size(); ++i) {
        if (i == diyi.size() - 1) {
            printf("%05d %d -1\n", diyi[i].first, diyi[i].second);
            continue;
        }
        printf("%05d %d %05d\n", diyi[i].first, diyi[i].second, diyi[i + 1].first);
    }
    for (int i = 0; i < dier.size(); ++i) {
        if (i == dier.size() - 1) {
            printf("%05d %d -1\n", dier[i].first, dier[i].second);
            continue;
        }
        printf("%05d %d %05d\n", dier[i].first, dier[i].second, dier[i + 1].first);
    }
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);

    solve();

    return 0;
}