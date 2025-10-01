impl Solution {
    pub fn max_bottles_drunk(num_bottles: i32, num_exchange: i32) -> i32 {
        let mut res = 0;
        let mut num_bottles = num_bottles;
        let mut num_exchange = num_exchange;
        while num_bottles > 0 {
            if num_bottles >= num_exchange {
                res += num_exchange;
                num_bottles -= num_exchange - 1;
                num_exchange += 1;
            } else {
                res += num_bottles;
                break;
            }
        }
        res
    }
}