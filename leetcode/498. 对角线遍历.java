class Solution {
    public int[] findDiagonalOrder(int[][] mat) {
        int m = mat.length, n = mat[0].length;
        int[] res = new int[m * n];
        int idx = 0;
        for (int i = 0; i < m + n - 1; i++) {
            if (i % 2 == 1) {
                int x, y;
                if (i < n) {
                    x = 0;
                    y = i;
                } else {
                    x = i - n + 1;
                    y = n - 1;
                }
                while (x < m && y >= 0) {
                    res[idx] = mat[x][y];
                    idx++;
                    x++;
                    y--;
                }
            } else {
                int x, y;
                if (i < m) {
                    x = i;
                    y = 0;
                } else {
                    x = m - 1;
                    y = i - m + 1;
                }
                while (x >= 0 && y < n) {
                    res[idx] = mat[x][y];
                    idx++;
                    x--;
                    y++;
                }
            }
        }
        return res;
    }
}