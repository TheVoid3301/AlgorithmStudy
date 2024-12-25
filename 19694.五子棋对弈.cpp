#include <iostream>
using namespace std;

int ans, g[7][7];

void dfs(int x, int y, int c) {
  if (c > 13)
    return;
  bool flag = false;
  // 检查x所在的列
  if (y == 5) {
    for (int i=1; i<=5; i++) if (g[x][i] != g[x][y]) { flag = true; break; }
    if (!flag) return;
  }
  flag = false;
  // 检查y所在的行
  if (x == 5) {
    for (int i=1; i<=5; i++) if (g[i][y] != g[x][y]) { flag = true; break; }
    if (!flag) return;
  }
  flag = false;
  // 检查左下到右上的斜边
  if (x == 5 && y == 1) {
    for (int i=1; i<=5; i++) if (g[i][6-i] != g[x][y]) { flag = true; break; }
    if (!flag) return;
  }
  flag = false;
  // 检查从左上到右下的斜边
  if (x == 5 && y == 5) {
    if (c != 13) return;
    for (int i=1; i<=5; i++) if (g[i][i] != g[x][y]) { flag = true; break; }
    if (!flag) return;
    ans++;
    return;
  }
  y++;
  if (y == 6)
    y = 1, x++;  
  
  g[x][y] = 0;
  dfs(x,y,c+1);
  g[x][y] = 1;
  dfs(x,y,c);
}

int main() {
  dfs(1,0,0); 
  cout<<ans<<'\n';
  
  return 0;
}