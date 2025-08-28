impl Solution {
    pub fn flower_game(n: i32, m: i32) -> i64 {
        (n as i64 / 2) * ((m as i64 + 1) / 2) + ((n as i64 + 1) / 2) * (m as i64 / 2)
    }
}