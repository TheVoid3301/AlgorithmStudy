impl Solution {
    pub fn new21_game(n: i32, k: i32, max_pts: i32) -> f64 {
        if k == 0 {
            return 1.0;
        }
        let mut dp = vec![0.0; (k + max_pts) as usize];
        for i in (k as usize..=n as usize){
            if i >= (k + max_pts) as usize {
                break;
            }
            dp[i] = 1.0;
        }
        dp[k as usize - 1] = 1.0 *  (std::cmp::min(n - k + 1, max_pts) as f64) / (max_pts as f64);
        if k >= 2 {
            for i in (0..=k as usize - 2).rev() {
                if i < 0 {
                    break;
                }
                dp[i] = dp[i + 1] - (dp[i + max_pts as usize + 1] - dp[i + 1]) / max_pts as f64;
            }
        }
        return dp[0];
    }
}