#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> heights(n);
    for (int i = 0; i < n; ++i) {
        cin >> heights[i];
    }
    int l, r, h;
    for (int i = 0; i < m; ++i) {
        cin >> l >> r >> h;
        for (int j = l - 1; j < r; ++j) {
            if (heights[j] > h) {
                heights[j] -= h;
            } else {
                cout << i + 1;
                return 0;
            }
        }
    }
    return 0;
}