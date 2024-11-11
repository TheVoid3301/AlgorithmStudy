/*
 * @lc app=leetcode.cn id=994 lang=cpp
 *
 * [994] 腐烂的橘子
 */

// @lc code=start
class Solution {
public:
    int cnt; //新鲜橘子的数量
    int dis[10][10]; //时间
    int dir_x[4] = {0, 1, 0, -1}; //x向量
    int dir_y[4] = {1, 0, -1, 0}; //y向量
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int , int>> Q; //同一时间准备腐烂其他橘子的橘子位置
        memset(dis, -1, sizeof(dis));
        cnt = 0;
        int n = grid.size(), m = grid[0].size(), ans = 0;
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < m; ++j)
            {
                if(grid[i][j] == 2)
                {
                    Q.push(make_pair(i, j)); //将一开始就腐烂的橘子加入队列
                    dis[i][j] = 0; //一开始腐烂的时间为0
                }
                else if(grid[i][j] == 1)
                {
                    ++cnt;
                }
            }
        }
        while(!Q.empty())
        {
            pair<int, int> a = Q.front();
            Q.pop();
            for(int i = 0; i < 4; ++i) //遍历Q队列中的腐烂橘子的上下左右四个方向
            {
                int tx = a.first + dir_x[i];
                int ty = a.second + dir_y[i];
                if (tx < 0|| tx >= n || ty < 0|| ty >= m || ~dis[tx][ty] || !grid[tx][ty]) 
                {
                    //如果当前橘子超过边缘或者此处没有橘子或者该点时间不是-1
                    continue;
                }
                dis[tx][ty] = dis[a.first][a.second] + 1; //只要是新鲜橘子就被腐烂，腐烂时间dis+1
                Q.push(make_pair(tx, ty)); //将上下左右四个方向的腐烂橘子或者原先为新鲜橘子被腐烂的橘子放入队列，进行下一时刻的循环，直到某一时刻队列中的所有腐烂橘子的四个方向没有橘子可以腐烂
                if(grid[tx][ty] == 1)
                {
                    --cnt;
                    ans = dis[tx][ty];
                    if(!cnt)
                    {
                        break;
                    }
                }
            }
        }
        return cnt ? -1 : ans;
    }
};
// @lc code=end

