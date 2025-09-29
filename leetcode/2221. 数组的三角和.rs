impl Solution {
    pub fn triangular_sum(nums: Vec<i32>) -> i32 {
        use std::collections as queue;
        let mut q: queue::VecDeque<i32> = nums.into();
        while q.len() > 1 {
            let n = q.len();
            for i in 0..n - 1 {
                let a = q.pop_front().unwrap();
                let b = q.front().unwrap();
                q.push_back((a + b) % 10);
                if i == n - 2 {
                    q.pop_front();
                }
            }
        }
        q.front().cloned().unwrap()
    }
}