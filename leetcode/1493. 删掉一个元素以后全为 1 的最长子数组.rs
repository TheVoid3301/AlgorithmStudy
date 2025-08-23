impl Solution {
    pub fn longest_subarray(nums: Vec<i32>) -> i32 {
        let mut dp: Vec<(i32, i32)> = Vec::new();
        let mut k = 0;
        let mut max_len = 0;
        while k < nums.len() {
            if nums[k] == 1 {
                let mut count: i32 = 0;
                while k < nums.len() && nums[k] == 1 {
                    count += 1;
                    k += 1;
                }
                dp.push(((k - 1) as i32, count));
                max_len = max_len.max(count);
            } else {
                k += 1;
            }
        }
        if max_len == nums.len() as i32 {
            return max_len - 1;
        }
        if dp.len() == 0 {
            return 0;
        }
        for i in 0..dp.len() - 1 {
            if dp[i + 1].0 - dp[i + 1].1 - dp[i].0 == 1 {
                max_len = max_len.max(dp[i].1 + dp[i + 1].1);
            }
        }
        max_len
    }
}