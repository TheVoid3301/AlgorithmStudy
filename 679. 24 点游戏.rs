impl Solution {
    pub fn judge_point24(cards: Vec<i32>) -> bool {
        let nums: Vec<f64> = cards.iter().map(|&x| x as f64).collect();
        Self::dfs(&nums)
    }

    fn dfs(nums: &[f64]) -> bool {
        if nums.len() == 0 {
            return false;
        }
        if nums.len() == 1 {
            return (nums[0] - 24.0).abs() < 1e-6;
        }
        for i in 0..nums.len() {
            for j in 0..nums.len() {
                if i == j {
                    continue;
                }
                let mut next_nums: Vec<f64> = nums.iter()
                    .enumerate()
                    .filter(|&(k, _)| k != i && k != j)
                    .map(|(_, &x)| x)
                    .collect();
                for op in 0..4 {
                    // Skip commutative operations when i > j to avoid duplicates
                    if op < 2 && i > j {
                        continue;
                    }
                    
                    let res = match op {
                        0 => nums[i] + nums[j],
                        1 => nums[i] * nums[j],
                        2 => nums[i] - nums[j],
                        3 => {
                            if nums[j].abs() < 1e-6 {
                                continue;
                            }
                            nums[i] / nums[j]
                        }
                        _ => unreachable!(),
                    };
                    
                    next_nums.push(res);
                    if Self::dfs(&next_nums) {
                        return true;
                    }
                    next_nums.pop();
                }
            }
        }
        false
    }
}