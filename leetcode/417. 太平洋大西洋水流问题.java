class Solution {
    public static final int[][] directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    public int[][] heights;

    public List<List<Integer>> pacificAtlantic(int[][] heights) {
        List<List<Integer>> result = new ArrayList<>();
        this.heights = heights;
        int m = heights.length;
        int n = heights[0].length;
        boolean[][] pacificReachable = new boolean[m][n];
        boolean[][] atlanticReachable = new boolean[m][n];
        for (int i = 0; i < m; i++) {
            dfs(i, 0, pacificReachable);
            dfs(i, n - 1, atlanticReachable);
        }
        for (int j = 0; j < n; j++) {
            dfs(0, j, pacificReachable);
            dfs(m - 1, j, atlanticReachable);
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacificReachable[i][j] && atlanticReachable[i][j]) {
                    result.add(Arrays.asList(i, j));
                }
            }
        }
        return result;
    }

    public void dfs(int row, int col, boolean[][] reachable) {
        if (reachable[row][col]) {
            return;
        }
        reachable[row][col] = true;
        for (int[] direction : directions) {
            int newRow = row + direction[0];
            int newCol = col + direction[1];
            if (newRow >= 0 && newRow < heights.length && newCol >= 0 
                && newCol < heights[0].length && heights[newRow][newCol] >= heights[row][col]) {
                dfs(newRow, newCol, reachable);
            }
        }
    }
}