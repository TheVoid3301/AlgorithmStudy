impl Solution {
    pub fn max_freq_sum(s: String) -> i32 {
        use std::collections::HashMap;
        
        let mut vowel_map: HashMap<char, i32> = HashMap::new();
        let mut consonant_map: HashMap<char, i32> = HashMap::new();
        
        // 定义元音字母集合（小写）
        let vowels = ['a', 'e', 'i', 'o', 'u'];
        
        for c in s.chars() {
            if vowels.contains(&c) {
                *vowel_map.entry(c).or_insert(0) += 1;
            } else {
                *consonant_map.entry(c).or_insert(0) += 1;
            }
        }
        
        // 找出元音中出现最多的频率
        let max_vowel_freq = vowel_map.into_iter().map(|(_, freq)| freq).max().unwrap_or(0);
        
        // 找出辅音中出现最多的频率
        let max_consonant_freq = consonant_map.into_iter().map(|(_, freq)| freq).max().unwrap_or(0);
        
        max_vowel_freq + max_consonant_freq
    }
}