impl Solution {
    pub fn find_duplicate(nums: Vec<i32>) -> i32 {
        use std::collections::HashSet;
        let mut set = HashSet::new();
        for num in &nums {
            if set.contains(num) {
                return *num;
            } else {
                set.insert(*num);
            }
        }
        -1
    }
}