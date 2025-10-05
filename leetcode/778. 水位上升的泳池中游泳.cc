#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        // 最小堆：存储 {时间（高度）, x, y}
        // 使用 vector<int> = {time, x, y}，按 time 排序
        auto cmp = [](const vector<int>& a, const vector<int>& b) {
            return a[0] > b[0];  // 最小堆：a[0] > b[0] 表示 a 优先级低
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> minHeap(cmp);

        // 起点入堆，初始时间为 grid[0][0]
        minHeap.push({grid[0][0], 0, 0});

        // visited 数组
        vector<vector<bool>> visited(n, vector<bool>(n, false));

        // distTo[i][j]：到达 (i,j) 所需的最少时间（即水位）
        vector<vector<int>> distTo(n, vector<int>(n, INT_MAX));
        distTo[0][0] = grid[0][0];

        // 四个方向：上、下、左、右
        vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while (!minHeap.empty()) {
            auto front = minHeap.top();
            minHeap.pop();

            int currentTime = front[0];
            int currentX = front[1];
            int currentY = front[2];

            // 如果已访问，跳过
            if (visited[currentX][currentY]) {
                continue;
            }

            // 标记为已访问
            visited[currentX][currentY] = true;

            // 到达终点
            if (currentX == n - 1 && currentY == n - 1) {
                return distTo[n - 1][n - 1];
            }

            // 遍历四个方向
            for (auto& dir : directions) {
                int newX = currentX + dir[0];
                int newY = currentY + dir[1];

                // 检查是否越界且未访问
                if (inArea(newX, newY, n) && !visited[newX][newY]) {
                    // 新的时间 = max(当前路径最大水位, 新格子的高度)
                    int newTime = max(distTo[currentX][currentY], grid[newX][newY]);

                    // 如果找到更短的时间路径
                    if (newTime < distTo[newX][newY]) {
                        distTo[newX][newY] = newTime;
                        minHeap.push({newTime, newX, newY});  // 入堆
                    }
                }
            }
        }

        return -1; // 理论上不会执行到这里
    }

private:
    // 检查坐标是否在网格范围内
    bool inArea(int x, int y, int n) {
        return x >= 0 && x < n && y >= 0 && y < n;
    }
};