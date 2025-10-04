impl Solution {
    pub fn pacific_atlantic(heights: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        const DIRECTIONS: [(i32, i32); 4] = [(0, 1), (0, -1), (1, 0), (-1, 0)];
        
        let m = heights.len();
        let n = heights[0].len();
        
        let mut pacific_reachable = vec![vec![false; n]; m];
        let mut atlantic_reachable = vec![vec![false; n]; m];
        let mut result = vec![];

        // 从太平洋边缘开始 DFS（左列和上行）
        for i in 0..m {
            Self::dfs(i, 0, &heights, &mut pacific_reachable);
        }
        for j in 0..n {
            Self::dfs(0, j, &heights, &mut pacific_reachable);
        }

        // 从大西洋边缘开始 DFS（右列和下行）
        for i in 0..m {
            Self::dfs(i, n - 1, &heights, &mut atlantic_reachable);
        }
        for j in 0..n {
            Self::dfs(m - 1, j, &heights, &mut atlantic_reachable);
        }

        // 收集能到达两个海洋的点
        for i in 0..m {
            for j in 0..n {
                if pacific_reachable[i][j] && atlantic_reachable[i][j] {
                    result.push(vec![i as i32, j as i32]);
                }
            }
        }

        result
    }

    // 辅助函数：DFS
    fn dfs(
        row: usize,
        col: usize,
        heights: &Vec<Vec<i32>>,
        reachable: &mut Vec<Vec<bool>>,
    ) {
        if reachable[row][col] {
            return;
        }
        reachable[row][col] = true;

        for &(dr, dc) in &DIRECTIONS {
            let new_row = (row as i32 + dr) as usize;
            let new_col = (col as i32 + dc) as usize;

            // 检查边界
            if new_row < heights.len() && new_col < heights[0].len() {
                // 水只能从高到低或等高流动
                if heights[new_row][new_col] >= heights[row][col] {
                    Self::dfs(new_row, new_col, heights, reachable);
                }
            }
        }
    }
}

const DIRECTIONS: [(i32, i32); 4] = [(0, 1), (0, -1), (1, 0), (-1, 0)];