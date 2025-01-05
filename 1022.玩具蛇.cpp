#include <iostream>
using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
int st[4][4];      // 记录已经走过的格子，避免重复走
int res = 0;       // 记录放置玩具蛇的方案数

void dfs(int x, int y, int len) {
    if (x < 0 || y < 0 || x >= 4 || y >= 4) {
        return;  // 超出边界，返回
    }
    if (st[x][y] == 1) {
        return;  // 已经走过，返回
    }
    if (len == 15) {
        res++;   // 玩具蛇的所有部分都已经放置，方案数加1
        return;
    }

    st[x][y] = 1;  // 标记当前格子已经走过
    // 向四个方向探索
    for (int i = 0; i < 4; i++) {
        dfs(x + dx[i], y + dy[i], len + 1);  // 递归探索下一个格子
    }
    st[x][y] = 0;  // 回溯，取消对当前格子的标记
}

int main() {
    // 从每个格子出发，探索放置玩具蛇的方案数
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            dfs(i, j, 0);
        }
    }
    cout << res << endl;  // 输出结果
    return 0;
}