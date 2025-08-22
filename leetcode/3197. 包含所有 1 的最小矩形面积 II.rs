impl Solution {
    fn minimum_sum2(grid: &Vec<Vec<i32>>, u: usize, d: usize, l: usize, r: usize) -> i32 {
        let mut min_i = grid.len();
        let mut max_i = 0;
        let mut min_j = grid[0].len();
        let mut max_j = 0;
        
        for i in u..=d {
            for j in l..=r {
                if grid[i][j] == 1 {
                    min_i = min_i.min(i);
                    min_j = min_j.min(j);
                    max_i = max_i.max(i);
                    max_j = max_j.max(j);
                }
            }
        }
        
        if min_i <= max_i {
            ((max_i - min_i + 1) * (max_j - min_j + 1)) as i32
        } else {
            i32::MAX / 3
        }
    }

    fn rotate(vec: &Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let n = vec.len();
        let m = if n > 0 { vec[0].len() } else { 0 };
        let mut ret = vec![vec![0; n]; m];
        
        for i in 0..n {
            for j in 0..m {
                ret[m - j - 1][i] = vec[i][j];
            }
        }
        
        ret
    }

    fn solve(grid: &Vec<Vec<i32>>) -> i32 {
        let n = grid.len();
        let m = if n > 0 { grid[0].len() } else { 0 };
        let mut res = (n * m) as i32;
        
        for i in 0..n-1 {
            for j in 0..m-1 {
                res = res.min(
                    Self::minimum_sum2(grid, 0, i, 0, m-1) +
                    Self::minimum_sum2(grid, i+1, n-1, 0, j) +
                    Self::minimum_sum2(grid, i+1, n-1, j+1, m-1)
                );
                
                res = res.min(
                    Self::minimum_sum2(grid, 0, i, 0, j) +
                    Self::minimum_sum2(grid, 0, i, j+1, m-1) +
                    Self::minimum_sum2(grid, i+1, n-1, 0, m-1)
                );
            }
        }
        
        for i in 0..n-2 {
            for j in i+1..n-1 {
                res = res.min(
                    Self::minimum_sum2(grid, 0, i, 0, m-1) +
                    Self::minimum_sum2(grid, i+1, j, 0, m-1) +
                    Self::minimum_sum2(grid, j+1, n-1, 0, m-1)
                );
            }
        }
        
        res
    }

    pub fn minimum_sum(grid: Vec<Vec<i32>>) -> i32 {
        let rgrid = Self::rotate(&grid);
        Self::solve(&grid).min(Self::solve(&rgrid))
    }
}