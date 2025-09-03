func findClosest(x int, y int, z int) int {
	if math.Abs(float64(x-z)) == math.Abs(float64(y-z)) {
		return 0
	} else {
		if math.Abs(float64(x-z)) > math.Abs(float64(y-z)) {
			return 2
		} else {
			return 1
		}
	}
}