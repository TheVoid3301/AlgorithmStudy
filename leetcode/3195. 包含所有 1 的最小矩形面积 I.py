class Solution:
    def minimumArea(self, grid: List[List[int]]) -> int:
        r1 = len(grid[0])
        d1 = len(grid)
        r2 = -1
        d2 = -1
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 1:
                    r1 = min(r1, j)
                    d1 = min(d1, i)
                    r2 = max(r2, j)
                    d2 = max(d2, i)
        return (r2 - r1 + 1) * (d2 - d1 + 1)