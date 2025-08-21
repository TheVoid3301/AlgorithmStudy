/*
 * @Description: 蓝桥国赛B组
 * @Auther: thevoid3301
 * @Date: 2025-07-28 21:07:52
 * @LastEditors: thevoid3301
 * @LastEditTime: 2025-07-28 21:45:59
 * @FilePath: \luogu\AB路线.cc
 */
#include <bits/stdc++.h>
using namespace std;
struct Node
{
	int x, y, deep, step;  // deep深度, step是一共走的步数, 初始位置也算一步, deep初始化是0, step初始化是1
};
const int N = 1e3 + 10;
int n, m, k; 
char g[N][N];
bool st[N][N][20];  // 打标记, 看之前是否走过, 防止进入死循环
int go[N][N] = {{0, 1}, {0, - 1}, {1, 0}, {-1, 0}};  // 四个方向可以走

int bfs()
{
	queue<Node> q;
	q.push({0, 0, 0, 1}); st[0][0][0] = true; 
	
	while (q.size())
	{
		auto t = q.front();
		q.pop();
		
		if (t.x == n - 1 && t.y == m - 1) return t.deep;  // 找到答案, 返回
		
		for (int i = 0; i < 4; i ++)
		{
			int aa = t.x + go[i][0], bb = t.y + go[i][1], stp = t.step + 1;
			
			if (aa < 0 || aa >= n || bb < 0 || bb >= m) continue;  // 超出边界, 跳过循环
			
			if (stp > k)   // 需要转换字符
			{
				stp = 1;
				if (g[aa][bb] == g[t.x][t.y]) continue;  // 如果字符跟原来相同, 跳过
			}
			else   // 不需要转换字符
			{
				if (g[aa][bb] != g[t.x][t.y]) continue;  // 如果字符跟原来不同, 跳过
			}
				
			if (!st[aa][bb][stp])  // 没有访问过
			{
				st[aa][bb][stp] = true;
				q.push({aa, bb, t.deep + 1, stp});
			}
		}
	}
	return -1;  // 没有找到答案, 无解
}

int main()
{
	cin >> n >> m >> k;
	
	for (int i = 0; i < n; i ++) cin >> g[i];
	int res = bfs();
	cout << res << endl;
	return 0;
}
