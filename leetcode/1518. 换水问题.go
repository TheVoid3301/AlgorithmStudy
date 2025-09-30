func numWaterBottles(numBottles int, numExchange int) int {
	if numBottles < numExchange {
		return numBottles
	}
	ans := numBottles
	empty := numBottles
	for empty >= numExchange {
		newBottles := empty / numExchange
		ans += newBottles
		empty = empty%numExchange + newBottles
	}
	return ans
}