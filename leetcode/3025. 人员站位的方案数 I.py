from typing import List

class Solution:
    def numberOfPairs(self, points: List[List[int]]) -> int:
        # 排序：按 x 升序，x 相同时按 y 降序
        points.sort(key=lambda p: (p[0], -p[1]))
        
        ans = 0
        n = len(points)
        
        for i in range(n):
            y1 = points[i][1]
            max_y = float('-inf')  # 记录从点 i 向右看时，当前最高点的 y 值
            
            for j in range(i + 1, n):
                y2 = points[j][1]
                
                # 条件：y2 <= y1（在下方或等高）且 y2 > max_y（未被前面的点挡住）
                if y2 <= y1 and y2 > max_y:
                    max_y = y2
                    ans += 1
                    
        return ans