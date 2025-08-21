impl Solution {
    pub fn count_hill_valley(nums: Vec<i32>) -> i32 {
        let mut res = 0;
        let n = nums.len();
        if n < 3 {
            return 0;
        }
        let mut processed = Vec::new();
        processed.push(nums[0]);
        for i in 1..n {
            if nums[i] != nums[i - 1] {
                processed.push(nums[i]);
            }
        }

        let m = processed.len();
        if m < 3 {
            return 0;
        }

        for i in 1..m - 1 {
            let left = processed[i - 1];
            let mid = processed[i];
            let right = processed[i + 1];
            if (left < mid && right < mid) {
                res += 1;
            } else if (left > mid && right > mid) {
                res += 1;
            }
        }
        
        res
    }
}