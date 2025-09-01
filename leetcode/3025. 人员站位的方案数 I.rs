impl Solution {
    pub fn number_of_pairs(points: Vec<Vec<i32>>) -> i32 {
        let mut points = points;
        
        // 排序：按 x 升序，x 相同时按 y 降序
        points.sort_by(|a, b| {
            a[0].cmp(&b[0]).then(b[1].cmp(&a[1]))
        });
        
        let mut ans = 0;
        
        for i in 0..points.len() {
            let y1 = points[i][1];
            let mut max_y = i32::MIN;  // 记录从 i 向右看时，当前最高点的 y 值
            
            for j in (i + 1)..points.len() {
                let y2 = points[j][1];
                
                // 条件：y2 <= y1（在下方或等高）且 y2 > max_y（未被挡住）
                if y2 <= y1 && y2 > max_y {
                    max_y = y2;
                    ans += 1;
                }
            }
        }
        
        ans
    }
}