#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N = 2e5 + 10;
const int mod  = 1e9 + 7;
//不开long long见祖宗
void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    ll ans = 0;
    bool flag = false;
    ll maxx = 0;
    for (int i = 2; i <= n; ++i) {
        ll tmp = abs(a[i] - a[i - 1]);
        maxx = max(maxx, tmp);
        if (tmp >= k) {
            flag = true;
            ans += tmp / k;
            if (tmp % k == 0) ans--;
        }
    }
    if (maxx ==  k) {
        cout << "0" << endl;
        return;
    }
    if (!flag) {
        cout << 1 << endl;
        return;
    }
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin>>t;
    while (t--) {
        solve();
    }
    return 0 ;
}
