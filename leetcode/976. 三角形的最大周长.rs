impl Solution {
    pub fn largest_perimeter(nums: Vec<i32>) -> i32 {
        let mut nums = nums;
        nums.sort();
        for i in 1..=nums.len() - 2 {
            if nums[nums.len() - i] < nums[nums.len() - i - 1] + nums[nums.len() - i - 2] {
                return nums[nums.len() - i] + nums[nums.len() - i - 1] + nums[nums.len() - i - 2];
            }
        }
        0
    }
}