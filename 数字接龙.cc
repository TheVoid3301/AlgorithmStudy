#include <bits/stdc++.h>
#include <limits>
#include <vector>

using namespace std;

int n, k;
vector<vector<int>> direct = {{-1, 0}, {-1, 1}, {0, 1}, 
    {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};


void dfs(vector<vector<int>> &v, int now, vector<int> &res, vector<vector<bool>> visited, int x, int y) {
    if (res.size() == n * n - 1) {
        return;
    }
    for (int i = 0; i < direct.size(); ++i) {
        int nx = x + direct[i][0];
        int ny = y + direct[i][i];
        if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
            if (v[nx][ny] == now && !visited[nx][ny]) {
                if (i == 1) {
                    if (!visited[nx - 1][ny] && !visited[nx][ny - 1]) {
                        res.push_back(i);
                        dfs()
                    }
                }
            }
        }
    }
}


int main() {
    cin >> n >> k;
    vector<vector<int>> v(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> v[i][j];
        }
    }
    vector<int> res;
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    dfs(v, 0, res, visited, 0, 0);

    return 1;
}