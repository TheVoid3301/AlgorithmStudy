#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int n;
long long m;
vector<vector<int>> road(501, vector<int>(501, INT_MAX));
int visit[501];
vector<int> dist(501, INT_MAX);

void dijkstra(int now)
{
  for(int i = 1; i <= n; ++i)
  {
    if(road[now][i] != INT_MAX && visit[i] != 1)
    {
      dist[i] = min(dist[i], dist[now] + road[now][i]);
    }
  }
  int min_d = INT_MAX, j = 0;
  for(int i = 1; i <= n; ++i)
  {
    if(min_d > dist[i] && visit[i] != 1)
    {
      min_d = dist[i];
      j = i;
    }
  }
  visit[j] = 1;
  if(j != 0)
  {
    dijkstra(j);
  }
}

int main()
{
  // 请在此输入您的代码
  int a, b, c;
  cin >> n >> m;
  for(long long i = 0; i < m; ++i)
  {
    cin >> a >> b >> c;
    road[a][b] = min(road[a][b], c);
  }
  visit[1] = 1;
  dist[1] = 0;
  dijkstra(1);
  if(dist[n] == INT_MAX)
  {
    cout << -1;
  }
  else
  {
    cout << dist[n];
  }
  return 0;
}