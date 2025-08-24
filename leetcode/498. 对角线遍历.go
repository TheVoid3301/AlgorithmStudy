func findDiagonalOrder(mat [][]int) []int {
	m := len(mat)
	n := len(mat[0])
	res := []int{}
	for i := 0; i < m+n-1; i++ {
		if i%2 == 1 {
			var x, y int
			if i < n {
				x = 0
				y = i
			} else {
				x = i - n + 1
				y = n - 1
			}
			for x < m && y >= 0 {
				res = append(res, mat[x][y])
				x++
				y--
			}
		} else {
			var x, y int
			if i < m {
				x = i
				y = 0
			} else {
				x = m - 1
				y = i - m + 1
			}
			for x >= 0 && y < n {
				res = append(res, mat[x][y])
				x--
				y++
			}
		}
	}
	return res
}