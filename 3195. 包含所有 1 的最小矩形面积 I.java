class Solution {
    public int minimumArea(int[][] grid) {
        int r1 = grid.length;
        int c1 = grid[0].length;
        int r2 = -1, c2 = -1;
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                if (grid[i][j] == 1) {
                    r1 = Math.min(r1, i);
                    c1 = Math.min(c1, j);
                    r2 = Math.max(r2, i);
                    c2 = Math.max(c2, j);
                }
            }
        }
        return (r2 - r1 + 1) * (c2 - c1 + 1);
    }
}