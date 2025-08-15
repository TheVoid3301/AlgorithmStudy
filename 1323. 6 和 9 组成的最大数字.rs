impl Solution {
    pub fn maximum69_number(num: i32) -> i32 {
        let mut num_str = num.to_string();
        
        let mut chars: Vec<char> = num_str.chars().collect();

        for i in 0..chars.len() {
            if chars[i] == '6' {
                chars[i] = '9';
                break; // 只替换第一个6
            }
        }
        
        let modified_str: String = chars.into_iter().collect();
        
        modified_str.parse().expect("Failed to parse number")
    }
}