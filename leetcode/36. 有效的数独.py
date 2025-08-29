from typing import List

class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        # 检查每一行
        for i in range(9):
            res_row = set()  # 为当前行创建一个新的集合
            for j in range(9):
                cell = board[i][j]
                # 如果不是空格 '.' 且该数字已在当前行出现过，则数独无效
                if cell != '.':
                    if cell in res_row: # 检查元素是否已在集合中
                        return False
                    res_row.add(cell) # 将数字添加到行集合中
        
        # 检查每一列
        for i in range(9):
            res_col = set() # 为当前列创建一个新的集合
            for j in range(9):
                cell = board[j][i]
                if cell != '.':
                    if cell in res_col:
                        return False
                    res_col.add(cell)
        
        # 检查每一个 3x3 子网格
        for i in range(0, 9, 3): # i 是子网格左上角的行索引，步长为3
            for j in range(0, 9, 3): # j 是子网格左上角的列索引，步长为3
                res_tan = set() # 为当前子网格创建一个新的集合
                # 遍历当前 3x3 子网格内的所有单元格
                for row in range(i, i + 3):
                    for col in range(j, j + 3):
                        cell = board[row][col]
                        if cell != '.':
                            if cell in res_tan:
                                return False
                            res_tan.add(cell)
        
        # 如果所有检查都通过，则数独有效
        return True