#include <bits/stdc++.h>
using namespace std;
int n, m, a[10005], f[10005][25], flag[10005];
string s;
int main()
{
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
  {
    cin >> a[i];
    f[i][0] = 1;
  }
  cin >> s;
  for (int i = 1; i <= n; i++)
  {
    flag[i] = s[i - 1] - '0';
    f[i][flag[i]] = 1;
    for (int j = 1; j < i; j++)
    {
      if (a[i] > a[j])
      {
        f[i][0]=max(f[i][0],f[j][0]+1);
        for (int k = 0; k <= m; k++)
        {
          f[i][k + flag[i]] = max(f[j][k]==0?0:f[j][k]+1, f[i][k + flag[i]]);
        }
      }
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++)
  {
    ans = max(ans, f[i][m]);
  }
  if(ans)  cout << ans << '\n';
  else cout<<-1<<'\n';
}