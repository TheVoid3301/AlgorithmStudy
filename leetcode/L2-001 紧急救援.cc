#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int maxn = 550;
int n,m,s,d,Maxv,cnt;
int val[maxn],vis[maxn],dist[maxn];
int G[maxn][maxn];
vector<int>ans,pre;
void dijkstra()
{
    memset(vis,0,sizeof(vis));
    for(int i = 0; i < n; i ++)dist[i] = G[s][i];
    int Min = inf;
    int v = -1;
    for(int i = 0; i < n; i ++)
    {
        Min = inf;
        v = -1;
        for(int j = 0; j < n; j ++)
        {
            if(!vis[j] && dist[j] <  Min)
            {
                Min = dist[j];
                v = j;
            }
        }
        vis[v] = 1;
        for(int j = 0; j < n; j ++)
        {
            if(!vis[j] && dist[j] > dist[v] + G[v][j])
            {
                dist[j] = dist[v] + G[v][j];
            }
        }
    }
}
void dfs(int x, int w)
{
    if(x == d)
    {
        if(w > Maxv)
        {
            Maxv = w;
            ans = pre;
        }
        cnt ++;
        return ;
    }
    for(int i = 0; i < n; i ++)
    {
        if(G[x][i] && !vis[i] && dist[i] == dist[x] + G[x][i])
        {
            vis[i] = 1;
            pre.push_back(i);
            dfs(i,w + val[i]);
            pre.pop_back();
            vis[i] = 0;
        }
    }
}
int main()
{
    int u,v,w;
    scanf("%d %d %d %d", &n, &m, &s, &d);
    for(int i = 0; i < n; i ++)
    {
        scanf("%d", &val[i]);
    }
    for(int i = 0; i <= n; i ++)
    {
        for(int j = 0; j <= n; j ++)
        {
            if(i != j)G[i][j] = inf;
            else G[i][j] = 0;
        }
    }
    for(int i = 0; i < m; i ++)
    {
        scanf("%d %d %d", &u, &v, &w);
        G[u][v] = w;
        G[v][u] = w;
    }
    dijkstra();
    Maxv = 0;
    cnt = 0;
    memset(vis,0,sizeof(vis));
    pre.push_back(s);
    dfs(s,val[s]);
    printf("%d %d\n",cnt,Maxv);
    int len = ans.size();
    for(int i = 0; i < len; i++)
    {
        if(i == 0) printf("%d",ans[i]);
        else printf(" %d",ans[i]);
    }
    printf("\n");
    return 0;
}