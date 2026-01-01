#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int res = 0, a, bit = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a;
        if (i > (a + ((bit + 1) % 10) * a)) {
            res += i;
        } else {
            res += (a + ((bit + 1) % 10) * a);
            bit++;
        }
    }
    cout << res;
    return 0;
}