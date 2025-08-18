func zeroFilledSubarray(nums []int) int64 {
	m := make(map[int]int)
	k := 0
	for _, v := range nums {
		if v == 0 {
			k++
		} else {
			if k > 0 {
				m[k]++
			}
			k = 0
		}
	}
	if k > 0 {
		m[k]++
	}
	ans := int64(0)
	for k, v := range m {
		for i := 1; i <= k; i++ {
			ans += int64(k-i+1) * int64(v)
		}
	}
	return ans
}