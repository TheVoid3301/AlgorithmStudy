class Solution {
    public boolean isValidSudoku(char[][] board) {
        // 使用 HashSet 来存储每一行、每一列、每一个3x3子网格中已见的数字
        java.util.HashSet<Character> resRow = new java.util.HashSet<>();
        java.util.HashSet<Character> resCol = new java.util.HashSet<>();
        java.util.HashSet<Character> resTan = new java.util.HashSet<>();

        // 检查每一行
        for (int i = 0; i < 9; i++) {
            resRow.clear(); // 清空行集合
            for (int j = 0; j < 9; j++) {
                char cell = board[i][j];
                // 如果不是空格 '.' 且该数字已在当前行出现过，则数独无效
                if (cell != '.') {
                    if (!resRow.add(cell)) { // HashSet.add() 方法如果元素已存在会返回 false
                        return false;
                    }
                    // 如果 add 返回 true，说明添加成功，无需显式插入（add 已经完成了）
                }
            }
        }

        // 检查每一列
        for (int i = 0; i < 9; i++) {
            resCol.clear(); // 清空列集合
            for (int j = 0; j < 9; j++) {
                char cell = board[j][i];
                if (cell != '.') {
                    if (!resCol.add(cell)) {
                        return false;
                    }
                }
            }
        }

        // 检查每一个 3x3 子网格
        for (int i = 0; i < 9; i += 3) { // i 是子网格左上角的行索引
            for (int j = 0; j < 9; j += 3) { // j 是子网格左上角的列索引
                resTan.clear(); // 清空当前子网格的集合
                // 遍历当前 3x3 子网格内的所有单元格
                for (int row = i; row < i + 3; row++) {
                    for (int col = j; col < j + 3; col++) {
                        char cell = board[row][col];
                        if (cell != '.') {
                            if (!resTan.add(cell)) {
                                return false;
                            }
                        }
                    }
                }
            }
        }

        // 如果所有检查都通过，则数独有效
        return true;
    }
}