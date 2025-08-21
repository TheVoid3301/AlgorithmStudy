#include <iostream>
#include <vector>
#include <queue>
using namespace std;
void bfs(queue<pair<int, int>>& q, vector<vector<char>>& res, int n, int m, int k)
{
  int q_size = q.size();
  while(k)
  {
    while(q_size)
    {
      pair<int, int> p = q.front();
      q.pop();
      q_size--;
      int x = p.first, y = p.second;
      if(x - 1 >= 0 && res[x - 1][y] != 'g')
      {
        q.push({x - 1, y});
        res[x - 1][y] = 'g';
      }
      if(y - 1 >= 0 && res[x][y - 1] != 'g')
      {
        q.push({x, y - 1});
        res[x][y - 1] = 'g';
      }
      if(y + 1 < m && res[x][y + 1] != 'g')
      {
        q.push({x, y + 1});
        res[x][y + 1] = 'g';
      }
      if(x + 1 < n && res[x + 1][y] != 'g')
      {
        q.push({x + 1, y});
        res[x + 1][y] = 'g';
      }
    }
    if(q_size == 0)
    {
      k--;
      q_size = q.size();
    }
  }
  for(int i = 0; i < n; ++i)
  {
    for(int j = 0; j < m; ++j)
    {
      cout << res[i][j];
    }
    cout << endl;
  }
}
int main()
{
  // 请在此输入您的代码
  int n, m, k;
  char c;
  cin >> n >> m;
  vector<vector<char>> res(n, vector<char>(m, 0));
  queue<pair<int, int>> q;
  for(int i = 0; i < n; ++i)
  {
    for(int j = 0; j < m; ++j)
    {
      cin >> c;
      res[i][j] = c;
      if(c == 'g')
      {
        q.push({i, j});
      }
    }
  }
  cin >> k;
  bfs(q, res, n, m, k);
  return 0;
}