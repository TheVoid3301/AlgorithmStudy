impl Solution {
    pub fn does_alice_win(s: String) -> bool {
        s.contains('a') || s.contains('e') || s.contains('i') || s.contains('o') || s.contains('u')
    }
}