func numberOfPairs(points [][]int) int {
	// 排序：按 x 升序，x 相同时按 y 降序
	sort.Slice(points, func(i, j int) bool {
		if points[i][0] != points[j][0] {
			return points[i][0] < points[j][0] // x 升序
		}
		return points[i][1] > points[j][1] // y 降序
	})

	ans := 0

	for i := 0; i < len(points); i++ {
		y1 := points[i][1]
		max_y := math.MinInt32 // 记录从点 i 向右看时，当前最高点的 y 值

		for j := i + 1; j < len(points); j++ {
			y2 := points[j][1]

			// 条件：y2 <= y1（在下方或等高）且 y2 > max_y（未被前面的点挡住）
			if y2 <= y1 && y2 > max_y {
				max_y = y2
				ans++
			}
		}
	}

	return ans
}