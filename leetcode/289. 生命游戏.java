class Solution {
    private int[][] a = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    public void gameOfLife(int[][] board) {
        int[][] res = new int[board.length][board[0].length];
        for (int i = 0; i < board.length; ++i) {
            for (int j = 0; j < board[0].length; ++j) {
                int cou = 0;
                for (int k = 0; k < a.length; ++k) {
                    int nx = i + a[k][0];
                    int ny = j + a[k][1];
                    if (nx >= 0 && nx < board.length && ny >= 0 && ny < board[0].length) {
                        if (board[nx][ny] == 1) {
                            cou++;
                        }
                    }
                }
                if (board[i][j] == 0 && cou == 3) {
                    res[i][j] = 1;
                } else if (board[i][j] == 1 && cou >= 2 && cou <= 3) {
                    res[i][j] = 1;
                }
            }
        }
        for (int i = 0; i < board.length; ++i) {
            for (int j = 0; j < board[0].length; ++j) {
                board[i][j] = res[i][j];
            }
        }
    }
}