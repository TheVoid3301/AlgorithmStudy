func minimumArea(grid [][]int) int {
	r1 := len(grid[0])
	d1 := len(grid)
	r2 := 0
	c2 := 0
	for i := 0; i < len(grid); i++ {
		for j := 0; j < len(grid[i]); j++ {
			if grid[i][j] == 1 {
				r1 = Min(r1, j)
				d1 = Min(d1, i)
				r2 = Max(r2, j)
				c2 = Max(c2, i)
			}
		}
	}
	return (r2 - r1 + 1) * (c2 - d1 + 1)
}

func Min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func Max(a, b int) int {
	if a > b {
		return a
	}
	return b
}