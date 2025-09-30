impl Solution {
    pub fn num_water_bottles(num_bottles: i32, num_exchange: i32) -> i32 {
        if num_bottles < num_exchange {
            return num_bottles;
        }
        let mut ans = num_bottles;
        let mut empty = num_bottles;
        while empty >= num_exchange {
            let new_bottles = empty / num_exchange;
            ans += new_bottles;
            empty = empty % num_exchange + new_bottles;
        }
        ans
    }
}