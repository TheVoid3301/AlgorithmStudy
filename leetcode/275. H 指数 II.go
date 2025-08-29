func hIndex(citations []int) int {
	if len(citations) == 1 {
		if citations[0] > 0 {
			return 1
		}
	}
	for i := len(citations); i >= 1; i-- {
		if citations[len(citations)-i] >= i {
			return i
		}
	}
	return 0
}