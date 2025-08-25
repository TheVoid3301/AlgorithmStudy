func areaOfMaxDiagonal(dimensions [][]int) int {
	max_len := 0
	max_area := 0
	for _, i := range dimensions {
		if i[0]*i[0]+i[1]*i[1] > max_len {
			max_len = i[0]*i[0] + i[1]*i[1]
			max_area = i[0] * i[1]
		} else if i[0]*i[0]+i[1]*i[1] == max_len {
			if i[0]*i[1] > max_area {
				max_area = i[0] * i[1]
			}
		}
	}
	return max_area
}