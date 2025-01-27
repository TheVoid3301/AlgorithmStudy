#include <iostream>
#include <vector>
using namespace std;
int a[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> res(n, vector<int>(m, 0)) ;
    char c;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> c;
            if (c == '*') {
                res[i][j] = -1;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (res[i][j] != -1) {
                int t = 0;
                for (int k = 0; k < 8; ++k) {
                    int ni =i + a[k][0];
                    int nj =j + a[k][1];
                    if (ni >= 0 && ni < n && nj >= 0 && nj < m && res[ni][nj] == -1) {
                        ++t;
                    }
                }
                res[i][j] = t;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (res[i][j] == -1) {
                cout << '*';
            } else {
                cout << res[i][j];
            }
        }
        cout << endl;
    }
    return 0;
}