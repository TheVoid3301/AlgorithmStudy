impl Solution {
    pub fn trap(height: Vec<i32>) -> i32 {
        if (height.len() <= 2) {
            return 0;
        }
        let mut l = 0;
        let mut r = 1;
        let mut res = 0;
        let mut now = 0;
        let mut lastl = 0;
        while r < height.len() {
            if height[l] > height[r] {
                now = now - height[r] + height[l];
                r += 1;
            } else {
                lastl = r;
                res += now;
                now = 0;
                l = r;
                r += 1;
            }
        }
        l = height.len() - 2;
        r = height.len() - 1;
        now = 0;
        while l >= lastl {
            if height[r] > height[l] {
                now = now + height[r] - height[l];
                if (l == 0) {
                    break;
                }
                l -= 1;
            } else {
                res += now;
                now = 0;
                r = l;
                if (l == 0) {
                    break;
                }
                l -= 1;
            }
        }
        res
    }
}