#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<bool>> a(n, vector<bool>(n, false));
    int x, y;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        a[x][y] = true;
    }
    cin >> x >> y;
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (a[x][i] && a[i][y]) {
            a[x][i] = false;
            a[i][y] = false;
            bool flag = false;
            for (int j = 0; j < n; j++) {
                if (a[i][j] && a[j][y]) {
                    flag = true;
                }
            }
            if (!flag) {
                res++;
            }
            a[x][i] = true;
            a[i][y] = true;
        }
    }
    if (res == 0) {
        cout << -1;
        return 0;
    }
    cout << res;
    return 0;
}