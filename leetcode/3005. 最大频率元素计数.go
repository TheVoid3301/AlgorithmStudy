func maxFrequencyElements(nums []int) int {
	m := make(map[int]int)
	maxCount := 0
	res := 0
	for _, num := range nums {
		m[num] += 1
	}
	for _, count := range m {
		if count > maxCount {
			maxCount = count
		}
	}
	for _, count := range m {
		if count == maxCount {
			res += maxCount
		}
	}
	return res
}