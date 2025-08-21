#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)

int main() {
    IOS;
    int T, x[5], y[5];
    cin >> T;
    while (T--) {
        for (int i = 1; i <= 3; i++) {
            cin >> x[i] >> y[i];
            if (i==3) {
                int tmx = x[i] - x[1], tmy = y[i] - y[1];
                int tmx2 = x[2] - x[i], tmy2 = y[2] - y[i];
                if(tmx * tmy2 == tmy * tmx2)    cout << "Yes";
                else cout << "No";
                cout << '\n';
            }
        }
    }
    return 0;
}