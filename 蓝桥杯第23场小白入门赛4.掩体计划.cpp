#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
vector<vector<int>> edge(N);
vector<int> bao;
vector<int> cnt(N);
int main()
{
  // 请在此输入您的代码
  int n;
  cin>>n;
  for(int i=0;i<n-1;i++)
  {
    int u,v;
    cin>>u>>v;
    edge[u].push_back(v);
  }
  int m;
  cin>>m;
  while(m--)
  {
    int temp;
    cin>>temp;
    bao.push_back(temp);
  }

  queue<int> q;
  q.push(1);
  while(!q.empty())
  {
    int f=q.front();
    q.pop();
    if(edge[f].size()>1) cnt[f]++;
    for(auto &i:edge[f])
    {
      if(!cnt[i])
      {
        cnt[i]=cnt[f];
        q.push(i);
      }
    }
  }
  int ans=1e9;
  for(auto i:bao)
  {
    ans=min(ans,cnt[i]);
  }
  cout<<ans;


  return 0;
}