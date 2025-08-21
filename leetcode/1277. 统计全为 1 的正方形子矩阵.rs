impl Solution {
    pub fn count_squares(matrix: Vec<Vec<i32>>) -> i32 {
        use std::cmp::min;
        let mut dp: Vec<Vec<i32>> = vec![vec![0; matrix[0].len()]; matrix.len()];
        let mut ans: i32 = 0;
        for i in 0..matrix.len() {
            for j in 0..matrix[0].len() {
                if i == 0 || j == 0 {
                    dp[i][j] = matrix[i][j];
                } else if matrix[i][j] == 0 {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = min(dp[i][j - 1], min(dp[i - 1][j], dp[i - 1][j - 1])) + 1;
                }
                ans += dp[i][j];
            }
        }
        ans
    }
}