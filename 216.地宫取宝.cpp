#include <bits/stdc++.h>
using namespace std;
const int N = 55, MOD = 1000000007;
 
int w[N][N], n, m, k;
int f[N][N][13][14];    
 
int main()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++) cin >> w[i][j], w[i][j] ++;
    
    // 初始化
    f[1][1][1][w[1][1]] = 1;  // 取
    f[1][1][0][0] = 1;        // 不取
    
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++)
        {
            if (i == 1 && j == 1) continue; // 初始话的跳过
            for (int u = 0; u <= k; u ++)
                for (int v = 0; v <= 13; v ++)
                {
                    f[i][j][u][v] = (f[i][j][u][v] + f[i][j - 1][u][v]) % MOD;  // 状态计算 1
                    f[i][j][u][v] = (f[i][j][u][v] + f[i - 1][j][u][v]) % MOD;  // 状态计算 2
                    if (u > 0 && w[i][j] == v)    // u > 0 加不加都行, 不影响答案, 因为 u == 0的时候表示什么都没选, 进入下面的循环也没意义
                    {
                        for (int c = 0; c < v; c ++)  // 常见问题解释的就是这里, 需要加上比 v 小的f, 才能让 f[i][j][k][c]表示的含义正确
                        {
                            f[i][j][u][v] = (f[i][j][u][v] + f[i][j - 1][u - 1][c]) % MOD; // 状态计算 3
                            f[i][j][u][v] = (f[i][j][u][v] + f[i - 1][j][u - 1][c]) % MOD; // 状态计算 4
                        }
                    }
                }
        }
    int res = 0;
    for (int i = 0; i <= 13; i ++) res = (res + f[n][m][k][i]) % MOD;
    cout << res << endl;
    return 0;
}