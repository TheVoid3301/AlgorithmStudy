impl Solution {
    pub fn h_index(citations: Vec<i32>) -> i32 {
        if citations.len() == 1 {
            return if citations[0] > 0 { 1 } else { 0 };
        }
        for i in (1..=citations.len() as i32).rev() {
            if citations[citations.len() - i as usize] >= i {
                return i;
            }
        }
        return 0;
    }
}