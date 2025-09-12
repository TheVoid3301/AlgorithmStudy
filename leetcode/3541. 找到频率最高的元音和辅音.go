func maxFreqSum(s string) int {
	vowels := map[byte]bool{
		'a': true,
		'e': true,
		'i': true,
		'o': true,
		'u': true,
	}

	vowelCount := make(map[byte]int)
	consonantCount := make(map[byte]int)

	// 遍历字符串，统计元音和辅音的频率
	for i := 0; i < len(s); i++ {
		char := s[i]
		if vowels[char] {
			vowelCount[char]++
		} else {
			consonantCount[char]++
		}
	}

	// 找出元音中出现的最大频率
	maxVowel := 0
	for _, freq := range vowelCount {
		if freq > maxVowel {
			maxVowel = freq
		}
	}

	// 找出辅音中出现的最大频率
	maxConsonant := 0
	for _, freq := range consonantCount {
		if freq > maxConsonant {
			maxConsonant = freq
		}
	}

	return maxVowel + maxConsonant
}