#include <iostream>
#include <vector>
using namespace std;

void floydWarshall(vector<vector<int>>& graph, int n) {
    // 初始化距离矩阵
    vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

    // 设置初始距离
    for (int i = 0; i < n; ++i) {
        dist[i][i] = graph[i][i];
        for (int j = 0; j < n; ++j) {
            if (graph[i][j] != INT_MAX) {
                dist[i][j] = graph[i][j];
            }
        }
    }

    // Floyd-Warshall 核心算法
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && 
                    dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}


int main() {
    printf("helloworld\n");
    fflush(stdout);
    int n;
    cin >> n;
    vector<vector<int>> graph(n, vector<int>(n, INT_MAX));
    for (int i = 0; i < n; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a][c] = b;
        graph[c][a] = b;
    }
    floydWarshall(graph, n);
    int maxn = 0;
    for (auto i : graph) {
        for (auto j : i) {
            if (j != INT_MAX) {
                maxn = max(maxn, j);
            }
        }
    }
    cout << (11 + (10 + maxn)) * maxn / 2 << endl;
    return 0;
}