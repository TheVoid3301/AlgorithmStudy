class Solution:
    def maxFreqSum(self, s: str) -> int:
        vowels = "aeiou"
        vowel_count = {}
        consonant_count = {}
        
        # 遍历字符串，统计元音和辅音的频率
        for char in s:
            if char in vowels:
                vowel_count[char] = vowel_count.get(char, 0) + 1
            else:
                consonant_count[char] = consonant_count.get(char, 0) + 1
        
        # 找出元音中出现最多的频率，如果无元音则为 0
        max_vowel = max(vowel_count.values()) if vowel_count else 0
        
        # 找出辅音中出现最多的频率，如果无辅音则为 0
        max_consonant = max(consonant_count.values()) if consonant_count else 0
        
        return max_vowel + max_consonant