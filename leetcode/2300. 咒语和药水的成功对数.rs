impl Solution {
    pub fn successful_pairs(spells: Vec<i32>, potions: Vec<i32>, success: i64) -> Vec<i32> {
        let m = potions.len();
        let mut required: Vec<i64> = Vec::with_capacity(m);
        
        // 预处理：计算每个药水所需的最小 spell 值（向上取整）
        for &potion in &potions {
            let potion64 = potion as i64;
            // 向上取整：ceil(success / potion)
            let req = (success + potion64 - 1) / potion64;
            required.push(req);
        }
        
        // 升序排序
        required.sort();
        
        let mut ans = Vec::with_capacity(spells.len());
        
        // 对每个 spell，二分查找有多少个 required <= spell
        for spell in spells {
            let spell64 = spell as i64;
            
            // 使用二分查找找到第一个 > spell64 的位置（即 upper_bound）
            let count = required.partition_point(|&x| x <= spell64);
            
            ans.push(count as i32);
        }
        
        ans
    }
}