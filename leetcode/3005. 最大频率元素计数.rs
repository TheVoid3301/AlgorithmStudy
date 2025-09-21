impl Solution {
    pub fn max_frequency_elements(nums: Vec<i32>) -> i32 {
        use std::collections::HashMap;
        let mut count_map = HashMap::new();
        for &num in &nums {
            *count_map.entry(num).or_insert(0) += 1;
        }
        let mut max_count = 0;
        let mut result = 0;
        for (_, count) in &count_map {
            if *count > max_count {
                max_count = *count;
            }
        }
        for (num, count) in &count_map {
            if *count == max_count {
                result += max_count;
            }
        }
        result
    }
}