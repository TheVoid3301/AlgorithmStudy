impl Solution {
    pub fn zero_filled_subarray(nums: Vec<i32>) -> i64 {
        let mut m = std::collections::HashMap::new();
        let mut ans: i64 = 0;
        let mut k = 0;
        for i in 0..nums.len() {
            if nums[i] == 0 {
                k += 1;
            } else {
                if k > 0 {
                    *m.entry(k).or_insert(0) += 1;
                }
                k = 0;
            }
        }
        if k > 0 {
            *m.entry(k).or_insert(0) += 1;
        }
        for (k, v) in m {
            for i in 1..=k {
                ans += (k as i64 - i as i64 + 1) * v as i64;
            }
        }
        ans
    }
}