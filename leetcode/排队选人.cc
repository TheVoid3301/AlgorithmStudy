#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, a, b;
    cin >> n >> k >> a >> b;
    vector<int> powers(n);
    vector<int> togethers(n);
    for (int i = 0; i < n; ++i) {
        cin >> powers[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> togethers[i];
    }
    int res = 0;
    for (int i = k - 1; i < n; ++i) {
        if (*min_element(powers.begin() + i - k + 1, powers.begin() + i + 1) >= a &&
            *min_element(togethers.begin() + i - k + 1, togethers.begin() + i + 1) >= b) {
            res++;
        }
    }
    cout << res << "\n";
    return 0;
}