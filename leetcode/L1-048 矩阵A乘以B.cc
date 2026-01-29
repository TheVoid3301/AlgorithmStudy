#include <bits/stdc++.h>

using namespace std;

#define ll long long
const ll MOD = 1e9 + 7;

void solve() {
    int ra, ca;
    cin >> ra >> ca;
    vector<vector<int>> a(ra, vector<int>(ca));
    for (int i = 0; i < ra; ++i) {
        for (int j = 0; j < ca; ++j) {
            cin >> a[i][j];
        }
    }
    int rb, cb;
    cin >> rb >> cb;
    vector<vector<int>> b(rb, vector<int>(cb));
    for (int i = 0; i < rb; ++i) {
        for (int j = 0; j < cb; ++j) {
            cin >> b[i][j];
        }
    }
    if (ca != rb) {
        cout << "Error: " << ca << " != " << rb;
        return;
    }
    vector<vector<int>> c(ra, vector<int>(cb));
    for (int i = 0; i < ra; ++i) {
        for (int j = 0; j < cb; ++j) {
            int sum = 0;
            for (int k = 0; k < ca; ++k) {
                sum += a[i][k] * b[k][j];
            }
            c[i][j] = sum;
        }
    }
    cout << ra << " " << cb << endl;
    for (int i = 0; i < ra; ++i) {
        for (int j = 0; j < cb; ++j) {
            if (j != cb - 1) {
                cout << c[i][j] << " ";
            } else {
                cout << c[i][j];
            }
        }
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}