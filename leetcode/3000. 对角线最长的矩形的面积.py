class Solution:
    def areaOfMaxDiagonal(self, dimensions: List[List[int]]) -> int:
        max_len = 0
        max_area = 0
        for i in dimensions:
            if i[0]*i[0]+i[1]*i[1] > max_len:
                max_len = i[0]*i[0]+i[1]*i[1]
                max_area = i[0]*i[1]
            elif i[0]*i[0]+i[1]*i[1] == max_len:
                max_area = max(max_area, i[0]*i[1])
        return max_area