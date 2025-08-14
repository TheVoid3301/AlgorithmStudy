impl Solution {
    pub fn is_power_of_four(n: i32) -> bool {
        let mut n = n;
        while n > 0 {
            if n == 1 {
                return true;
            }
            if n % 4 != 0 {
                return false;
            }
            n /= 4;
        }
        false
    }
}