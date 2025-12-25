#include <bits/stdc++.h>
using namespace std;

int mins = INT_MAX;

void dfs(vector<vector<int>> &graph, vector<bool> &visited, 
            int cx, int endx, vector<int> &path, vector<vector<int>> &allPaths,int cur) {
    if (cx == endx) {
        allPaths.push_back(path);
        mins = min(mins, cur);
        return;
    }
    for (int i = 0; i < (int)visited.size(); ++i) {
        if (!visited[i] && graph[cx][i] != INT_MAX) {
            visited[i] = true;
            path.push_back(i);
            cur += graph[cx][i];
            dfs(graph, visited, i, endx, path, allPaths, cur);
            cur -= graph[cx][i];
            visited[i] = false;
            path.pop_back();
        }
    }
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, c1, c2;
    cin >> n >> m >> c1 >> c2;
    vector<int> number(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> number[i];
    }
    vector<vector<int>> graph(n, vector<int>(n, INT_MAX));
    vector<bool> visited(n, false);
    vector<int> path;
    vector<vector<int>> allPaths;
    visited[c1] = true;
    int a, b;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        int weight;
        cin >> weight;
        graph[a][b] = weight;
        graph[b][a] = weight;
    }
    path.push_back(c1);
    dfs(graph, visited, c1, c2, path, allPaths, 0);
    int count = 0;
    int maxPeople = 0;
    for (auto &p : allPaths) {
        int people = 0;
        int dist = 0;
        for (int i = 1; i < (int)p.size(); ++i) {
            dist += graph[p[i - 1]][p[i]];
        }
        if (dist != mins) {
            continue;
        }
        count++;
        for (auto &city : p) {
            people += number[city];
        }
        maxPeople = max(maxPeople, people);
    }
    cout << count << " " << maxPeople << "\n";
    return 0;
}
