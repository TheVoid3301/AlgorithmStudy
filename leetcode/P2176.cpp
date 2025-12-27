#include <bits/stdc++.h>
#include <climits>
using namespace std;

int minn = INT_MAX;
vector<pair<int, int>> res;

void dfs(vector<vector<int>> &adj, vector<bool> &visited, int node, vector<pair<int, int>> &edges) {
    if (node == adj.size() - 1) {
        int total_weight = 0;
        for (auto &edge : edges) {
            total_weight += adj[edge.first][edge.second];
        }
        if (total_weight < minn) {
            minn = total_weight;
            res = edges;
        }
        return;
    }
    visited[node] = true;
    for (int neighbor = 1; neighbor < adj.size(); ++neighbor) {
        if (adj[node][neighbor] != INT_MAX && !visited[neighbor]) {
            edges.push_back({node, neighbor});
            dfs(adj, visited, neighbor, edges);
            edges.pop_back();
        }
    }
    visited[node] = false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1, vector<int>(n + 1, INT_MAX));
    vector<pair<int, int>> edges;
    vector<pair<int, int>> temp_edges;
    for (int i = 0; i < m; ++i) {
        int x, y, w;
        cin >> x >> y >> w;
        adj[x][y] = w;
        temp_edges.push_back({x, y});
    }
    vector<bool> visited(n + 1, false);
    dfs(adj, visited, 1, edges);
    int r = INT_MAX;
    pair<int, int> io;
    for (int i = 0; i < res.size(); ++i) {
        if (2 * adj[res[i].first][res[i].second] < r) {
            r = 2 * adj[res[i].first][res[i].second];
            io = res[i];
        }
    }
    for (int i = 0; i < temp_edges.size(); ++i) {
        if (temp_edges[i] == io) {
            r = i;
            break;
        }
    }
    cout << r + 1;
    return 0;
}