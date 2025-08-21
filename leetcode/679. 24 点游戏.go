func judgePoint24(cards []int) bool {
	nums := make([]float64, len(cards))
	for i, num := range cards {
		nums[i] = float64(num)
	}
	return dfs(nums)
}

func dfs(nums []float64) bool {
	if len(nums) == 0 {
		return false
	}
	if len(nums) == 1 {
		return math.Abs(nums[0]-24) < 1e-6
	}
	for i := 0; i < len(nums); i++ {
		for j := 0; j < len(nums); j++ {
			if i == j {
				continue
			}
			nextNums := make([]float64, 0, len(nums)-1)
			for k := 0; k < len(nums); k++ {
				if k != i && k != j {
					nextNums = append(nextNums, nums[k])
				}
			}
			for op := 0; op < 4; op++ {
				if op < 2 && i > j {
					continue
				}
				var res float64
				switch op {
				case 0:
					res = nums[i] + nums[j]
				case 1:
					res = nums[i] * nums[j]
				case 2:
					res = nums[i] - nums[j]
				case 3:
					if math.Abs(nums[j]) < 1e-6 {
						continue
					}
					res = nums[i] / nums[j]
				}
				nextNums = append(nextNums, res)
				if dfs(nextNums) {
					return true
				}
				nextNums = nextNums[:len(nextNums)-1]
			}
		}
	}
	return false
}