impl Solution {
    pub fn minimum_area(grid: Vec<Vec<i32>>) -> i32 {
        let mut r1 = grid.len() as i32;
        let mut r2 = -1;
        let mut c1 = grid[0].len() as i32;
        let mut c2 = -1;
        for i in 0..grid.len() {
            for j in 0..grid[0].len() {
                if grid[i][j] == 1 {
                    r1 = r1.min(i as i32);
                    r2 = r2.max(i as i32);
                    c1 = c1.min(j as i32);
                    c2 = c2.max(j as i32);
                }
            }
        }
        (r2 - r1 + 1) * (c2 - c1 + 1)
    }
}