impl Solution {
    pub fn area_of_max_diagonal(dimensions: Vec<Vec<i32>>) -> i32 {
        let mut max_len = 0;
        let mut max_area = 0;
        for i in dimensions {
            if i[0] * i[0] + i[1] * i[1] > max_len {
                max_len = i[0] * i[0] + i[1] * i[1];
                max_area = i[0] * i[1];
            } else if i[0] * i[0] + i[1] * i[1] == max_len {
                max_area = max_area.max(i[0] * i[1]);
            }
        }
        max_area
    }
}