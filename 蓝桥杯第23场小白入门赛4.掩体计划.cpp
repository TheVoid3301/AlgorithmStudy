#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
vector<vector<int>> edge(N);
vector<int> bao;
vector<int> cnt(N);
int main()
{
  int n;
  cin>>n;
  // 遍历写入i点与哪些点相连
  for(int i=0;i<n-1;i++)
  {
    int u,v;
    cin>>u>>v;
    edge[u].push_back(v);
  }
  int m;
  cin>>m;
  // 遍历写入核弹的位置
  while(m--)
  {
    int temp;
    cin>>temp;
    bao.push_back(temp);
  }

  queue<int> q;
  // 将根节点（信号初始节点）放入队列
  q.push(1);
  while(!q.empty())
  {
    int f=q.front();
    q.pop();
    // 如果该点与多条路径相连接，则该点需要的控制器+1
    if(edge[f].size()>1) cnt[f]++;
    // 循环遍历与该点相连的其他点
    for(auto &i:edge[f])
    {
      // 如果该点没有被遍历过，则该点所需控制器设置为f点的控制器数量
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