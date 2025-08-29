impl Solution {
    pub fn is_valid_sudoku(board: Vec<Vec<char>>) -> bool {
        use std::collections::HashSet;
        let mut resRow: HashSet<char> = HashSet::new();
        let mut resCol: HashSet<char> = HashSet::new();
        let mut resTan: HashSet<char> = HashSet::new();
        for i in 0..9 {
            for j in 0..9 {
                if board[i][j] != '.' && resRow.contains(&board[i][j]) {
                    return false;
                }
                resRow.insert(board[i][j]);
            }
            resRow.clear();
        }
        for i in 0..9 {
            for j in 0..9 {
                if board[j][i] != '.' && resCol.contains(&board[j][i]) {
                    return false;
                }
                resCol.insert(board[j][i]);
            }
            resCol.clear();
        }
        for i in (0..9).step_by(3) {
            for j in i..i + 3 {
                for k in 0..3 {
                    if board[j][k] != '.' && resTan.contains(&board[j][k]) {
                        return false;
                    }
                    resTan.insert(board[j][k]);
                }
            }
            resTan.clear();
            for j in i..i + 3 {
                for k in 3..6 {
                    if board[j][k] != '.' && resTan.contains(&board[j][k]) {
                        return false;
                    }
                    resTan.insert(board[j][k]);
                }
            }
            resTan.clear();
            for j in i..i + 3 {
                for k in 6..9 {
                    if board[j][k] != '.' && resTan.contains(&board[j][k]) {
                        return false;
                    }
                    resTan.insert(board[j][k]);
                }
            }
            resTan.clear();
        }
        return true;
    }
}