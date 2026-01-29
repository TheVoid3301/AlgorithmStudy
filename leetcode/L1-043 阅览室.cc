#include <bits/stdc++.h>

using namespace std;

#define ll long long

int get_time(int a, int b, pair<int, int> c) {
    int a2 = c.first,  b2 = c.second;
    return abs(a * 60 + b - a2 * 60 - b2);
}

void solve() {
    int n;
    cin >> n;
    int h, hh, mm;
    char k;
    map<int, pair<int, int>> m;
    int ci = 0, sum = 0;
    while (n) {
        cin >> h >> k >> hh;
        getchar();
        cin >> mm;
        if (h == 0) {
            if (ci != 0) {
                cout << ci << " " << round((double)sum / ci) << endl;
            } else {
                cout << 0 << " " << 0 << endl;
            }
            ci = 0;
            sum = 0;
            --n;
            m.clear();
        } else {
            if (k == 'S') {
                m[h] = make_pair(hh, mm);
            } else {
                if (m.contains(h)) {
                    if (m[h].first <= 24) {
                        ci++;
                    }
                    sum += get_time(hh, mm, m[h]);
                    m.erase(h);
                }
            }
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