#include<bits/stdc++.h>
using namespace std;
#define inf INT_MAX
#define maxn 1010
int graph[maxn][maxn];
void initEdges(int n)
{
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            graph[i][j]=inf;
        }
    }
}
void addEdge(int u, int v ,int w)
{
    if(w<graph[u][v])
    graph[u][v]=w;
}
void dijkstra(int n,int s,int dist[maxn])
{
  bool visited[maxn];
  for(int i=0;i<n;i++)
  {
    visited[i]=false;
    dist[i]=inf;
  }
  dist[s]=0;
    while(true)
    {    
    int Mindist=inf,MinIndex;
        for(int i=0;i<n;i++)
        {
            if(visited[i]==true)
            continue;
            if(Mindist>dist[i]||Mindist==inf)
            {
                Mindist=dist[i];
                MinIndex=i;
            }
        }
        if(Mindist==inf)
        break;
        visited[MinIndex]=true;
        for(int i=0;i<n;i++)
            {
                if(visited[i])
                continue;
                int dis=graph[MinIndex][i];
                if(dis==inf){
                    continue;
                }
                if(dist[i]==inf||dist[MinIndex]+dis<dist[i]){
                    dist[i]=dis+dist[MinIndex];
                }
            }
    }
}
int main()
{
  int n,m;
  cin>>n>>m;
  int u,v,w;
  initEdges(n);
  for(int i=0;i<m;i++){
    cin>>u>>v>>w;
    addEdge(u-1,v-1,w);//初始化
  }
  int dist[maxn];
  dijkstra(n,0,dist);
  if(dist[n-1]==inf)
  cout<<-1;
  else
  cout<<dist[n-1];
}