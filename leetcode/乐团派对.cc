#include <functional>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int res = -1;
    sort(a.begin(), a.end(), greater<int>());
    int i = 0;
    while (i < n) {
        int t = a[i];
        if (i + a[i] - 1 < n) {
            if (res == -1) {
                res = 1;
            } else {
                res++;
            }
            i += a[i];
        } else {
            ++i;
        }
    }
    cout << res;
    return 0;
}
// 64 位输出请用 printf("%lld")