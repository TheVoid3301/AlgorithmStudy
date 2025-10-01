func maxBottlesDrunk(numBottles int, numExchange int) int {
	res := 0
	for numBottles > 0 {
		if numBottles >= numExchange {
			res += numExchange
			numBottles -= numExchange - 1
			numExchange++
		} else {
			res += numBottles
			break
		}
	}
	return res
}