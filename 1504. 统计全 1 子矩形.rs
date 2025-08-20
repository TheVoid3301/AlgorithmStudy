impl Solution {
    pub fn num_submat(mat: Vec<Vec<i32>>) -> i32 {
        let (m, n) = (mat.len(), mat[0].len());
        let mut res = 0;
        let mut row = vec![vec![0; n]; m];
        for i in 0..m {
            for j in 0..n {
                if j == 0 {
                    row[i][j] = mat[i][j];
                } else {
                    row[i][j] = if mat[i][j] == 0 { 
                        0 
                    } else { 
                        row[i][j - 1] + 1 
                    };
                }
                let mut cur = row[i][j];
                for k in (0..=i).rev() {
                    cur = cur.min(row[k][j]);
                    if cur == 0 {
                        break;
                    }
                    res += cur;
                }
            }
        }
        res
    }
}