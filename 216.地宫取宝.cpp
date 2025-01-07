#include<bits/stdc++.h>
using namespace std;
int n, m, k;
int a[55][55];//输入所给数组值所分配的内存空间
int dp[55][55][15][15];//开创记忆化的存储空间
//因为只进行向下走和向右走，所有写成这个样子，不明白的可以在了解以下笛卡尔积，向下是x轴，向右是y轴(一般情况下)
int dx[] = {1,0};
int dy[] = {0,1};
int p = 1e9+7;//索取余数
//dfs()里面写x,y,mx,cnt分别代表更新的坐标，最大值，宝物数目
long long dfs(int x, int y, int mx, int cnt)
{
  if(x == n && y == m)  return cnt == k;//这个是结束临界条件，到最后结束跳出
  if(dp[x][y][mx][cnt] != -1)   return  dp[x][y][mx][cnt];//进行记忆化搜索的地方，如果之前保存过这个值就不用再次计算而是直接使用保存过的值(值不会因为后续深搜改变的改变而是不变)
  long long res = 0;//后续进行记忆化存储的给予赋值
  for(int i = 0; i < 2; i++){
  //进行向下或者向右的搜索
      int nx = x + dx[i];
      int ny = y + dy[i];
      if(nx < 1 || ny < 1 || nx > n || ny > m)  continue;
  //拿这个东西
      if(a[nx][ny] > mx && cnt < k) res = (res + dfs(nx, ny, a[nx][ny], cnt + 1)) % p;
  //不拿这个东西
      res = (res + dfs(nx, ny, mx, cnt)) % p;
  }
  //进行记忆化搜索的重要部分
  return dp[x][y][mx][cnt] = res;
}
int main(){
   //将dp数组置为-1，不置为0是因为宝物价值可能为0出现异议
    memset(dp, -1, sizeof dp);
    cin >> n >> m >> k;
    for(int i = 1;i <= n; i++)
    {        
      for(int j = 1; j <= m; j++)
      {
        cin >> a[i][j];
        a[i][j]++;
   //这里的++是为了让宝物价值最小也为1，问题问的是路线情况，并不用担心价值问题
      }
    }
   //对一开始的宝物拿和不拿都进行深搜获得最终答案         
    cout << (dfs(1, 1, 0, 0) + dfs(1, 1, a[1][1], 1)) % p << endl;
    return 0;
}