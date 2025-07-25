impl Solution {
    pub fn length_of_last_word(s: String) -> i32 {
        let s = s.trim();
        let mut res = s.len();
        for (i, n) in s.chars().rev().enumerate() {
            if (n == ' ') {
                res = i;
                break;
            }
        }
        let res:i32 = res as i32;
        res
    }
}