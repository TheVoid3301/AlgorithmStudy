impl Solution {
    pub fn can_be_typed_words(text: String, broken_letters: String) -> i32 {
        use std::collections::HashSet;
        let broken: HashSet<char> = broken_letters.chars().collect();

        let mut count = 0;
        for word in text.split_whitespace() {
            if !word.chars().any(|c| broken.contains(&c)) {
                count += 1;
            }
        }
        count
    }
}