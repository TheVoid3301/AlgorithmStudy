impl Solution {
    pub fn is_power_of_three(n: i32) -> bool {
        let mut n = n;
        while (n > 0) {
            if (n == 1) {
                return true;
            }
            if (n % 3 != 0) {
                return false;
            }
            n /= 3;
        }
        false
    }
}