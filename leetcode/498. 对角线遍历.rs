impl Solution {
    pub fn find_diagonal_order(mat: Vec<Vec<i32>>) -> Vec<i32> {
        let m = mat.len();
        let n = mat[0].len();
        let mut result = Vec::new();
        for i in 0..(m + n - 1) {
            let mut x: i32;
            let mut y: i32;
            if i % 2 == 1 {
                if i < n {
                    x = 0;
                    y = i as i32;
                } else {
                    x = i as i32 - n as i32 + 1;
                    y = n as i32 - 1;
                }
                while x < m as i32 && y >= 0 {
                    result.push(mat[x as usize][y as usize]);
                    x += 1;
                    y -= 1;
                }
            } else {
                if i < m {
                    x = i as i32;
                    y = 0;
                } else {
                    x = m as i32 - 1;
                    y = i as i32 - m as i32 + 1;
                }
                while x >= 0 && y < n as i32 {
                    result.push(mat[x as usize][y as usize]);
                    x -= 1;
                    y += 1;
                }
            }
        }
        return result;
    }
}