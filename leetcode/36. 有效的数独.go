func isValidSudoku(board [][]byte) bool {
	// 使用 map[byte]struct{} 作为 Set 来存储已见的数字
	resRow := make(map[byte]struct{})
	resCol := make(map[byte]struct{})
	resTan := make(map[byte]struct{})

	// 检查每一行
	for i := 0; i < 9; i++ {
		// 清空行集合
		for k := range resRow {
			delete(resRow, k)
		}
		for j := 0; j < 9; j++ {
			cell := board[i][j]
			// 如果不是空格 '.' 且该数字已在当前行出现过，则数独无效
			if cell != '.' {
				if _, exists := resRow[cell]; exists {
					return false
				}
				resRow[cell] = struct{}{} // 将数字加入行集合
			}
		}
	}

	// 检查每一列
	for i := 0; i < 9; i++ {
		// 清空列集合
		for k := range resCol {
			delete(resCol, k)
		}
		for j := 0; j < 9; j++ {
			cell := board[j][i]
			if cell != '.' {
				if _, exists := resCol[cell]; exists {
					return false
				}
				resCol[cell] = struct{}{}
			}
		}
	}

	// 检查每一个 3x3 子网格
	for i := 0; i < 9; i += 3 { // i 是子网格左上角的行索引
		for j := 0; j < 9; j += 3 { // j 是子网格左上角的列索引
			// 清空当前子网格的集合
			for k := range resTan {
				delete(resTan, k)
			}
			// 遍历当前 3x3 子网格内的所有单元格
			for row := i; row < i+3; row++ {
				for col := j; col < j+3; col++ {
					cell := board[row][col]
					if cell != '.' {
						if _, exists := resTan[cell]; exists {
							return false
						}
						resTan[cell] = struct{}{}
					}
				}
			}
		}
	}

	// 如果所有检查都通过，则数独有效
	return true
}