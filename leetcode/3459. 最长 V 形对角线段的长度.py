class Solution:
    def lenOfVDiagonal(self, grid: List[List[int]]) -> int:
        DIRS = [(1, 1), (1, -1), (-1, -1), (-1, 1)]
        m, n = len(grid), len(grid[0])
        
        @cache
        def dfs(cx, cy, direction, turn, target):
            nx, ny = cx + DIRS[direction][0], cy + DIRS[direction][1]
            # 如果超出边界或者下一个节点值不是目标值，则返回 
            if nx < 0 or ny < 0 or nx >= m or ny >= n or grid[nx][ny] != target:
                return 0
            turn_int = 1 if turn else 0
            # 按照原来的方向继续行走
            max_step = dfs(nx, ny, direction, turn, 2 - target)
            if turn:
                # 顺时针旋转 90 度转向
                max_step = max(max_step, dfs(nx, ny, (direction + 1) % 4, False, 2 - target))
            return max_step + 1
        
        res = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    for direction in range(4):
                        res = max(res, dfs(i, j, direction, True, 2) + 1)
        return res
