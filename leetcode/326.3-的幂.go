func isPowerOfThree(n int) bool {
	if n == 0 {
		return false
	}

	for n >= 0 {
		if n == 1 || n == 0 {
			return true
		}
		if n%3 != 0 {
			return false
		}
		n /= 3
	}
	return false
}