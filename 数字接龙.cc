#include <iostream>
#include <string>
using namespace std;
const int N=20;
string ans;
int g[N][N];//图 
bool vis[N][N];//访问标记 
int path[N][N];//记录每个点的移动方向 
        // 0  1 2 3 4 5 6  7
int dx[]={-1,-1,0,1,1,1,0,-1};
        //0 1 2 3 4  5  6  7
int dy[]={0,1,1,1,0,-1,-1,-1};
int n,k;//题目输入 
       //起点      //当前值  //当前组成的字串 
void dfs(int x,int y,int cur,string s,int dep)//搜索点的个数 
{
    if(x==n-1&&y==n-1&&dep==n*n)//搜到了(n-1,n-1)，并且搜过了所有的点 
    {
        if(ans.empty()) ans=s;
        return;
    }
    for(int i=0;i<8;i++)//八方向搜索 
    {
        int bx=x+dx[i],by=y+dy[i];
        if(bx<0||bx>n-1||by<0||by>n-1) continue;
        if(vis[bx][by]) continue;
        //判交叉
        if(i==1&&(path[bx][by-1]==3||path[bx+1][by]==7)) continue;
        else if(i==3&&(path[bx-1][by]==5||path[bx][by-1]==1)) continue;
        else if(i==5&&(path[bx-1][by]==3||path[bx][by+1]==7)) continue;
        else if(i==7&&(path[bx+1][by]==1||path[bx][by+1]==5)) continue;
        //保证是0,1,2…k-1,0
        if((cur<k-1&&g[bx][by]==cur+1)||(cur==k-1&&g[bx][by]==0))
        {
            vis[bx][by]=1;
            path[x][y]=i;//记录当前点所移动的方向 
            dfs(bx,by,g[bx][by],s+to_string(i),dep+1);
            if(!ans.empty()) return;//不空表示已经第一次找到了，不用回溯 
            vis[bx][by]=0;
            path[x][y]=-1;//回溯则重置 
        }
    }
}
int main()
{
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>g[i][j];
            path[i][j]=-1;//初始化记录 
        }
    }
    string star;//初始空字符串
    vis[0][0]=1;//标记(0,0)已经被访问 
    dfs(0,0,0,star,1);
    if(!ans.empty()) cout<<ans;
    else cout<<"-1";
    return 0; 
}