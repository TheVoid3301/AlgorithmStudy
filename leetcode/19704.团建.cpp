#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N = 2e5+10;
int c[N],d[N];
map<int,vector<int>>mp1;
map<int,vector<int>>mp2;
int maxx = 0;
void dfs(int x,int y,int cnt)
{
  if(c[x]!=d[y])
  {
    return;
  }
  maxx = max(cnt+1,maxx);
  int s1 = mp1[x].size();
  int s2 = mp2[y].size();
  for(int i = 0;i<s1;i++)
  {
    for(int j = 0;j<s2;j++)
    {
      dfs(mp1[x][i],mp2[y][j],cnt+1);
    }
  }
}
int main()
{
  cin>>n>>m;
  for(int i = 1;i<=n;i++) cin>>c[i];
  for(int i = 1;i<=m;i++) cin>>d[i];
  for(int i = 1;i<=n-1;i++)
  {
    int a,b;
    cin>>a>>b;
    if(a > b)
    {
      swap(a, b);
    }
    mp1[a].push_back(b);
  }
  for(int i = 1;i<=m-1;i++)
  {
    int a,b;
    cin>>a>>b;
    if(a > b)
    {
      swap(a, b);
    }
    mp2[a].push_back(b);
  }
  dfs(1,1,0);
  cout<<maxx<<endl;
  return 0;
}