import java.util.*;

class Solution {
    public int[] successfulPairs(int[] spells, int[] potions, long success) {
        int n = spells.length;
        int m = potions.length;
        
        // 预处理：计算每个药水所需的最小 spell 强度
        long[] required = new long[m];
        for (int i = 0; i < m; i++) {
            // 向上取整：ceil(success / potions[i])
            required[i] = (success + potions[i] - 1) / potions[i]; // 避免浮点运算
        }
        
        // 排序 required 数组（升序）
        Arrays.sort(required);
        
        int[] ans = new int[n];
        
        // 对每个 spell，二分查找有多少个 required <= spell
        for (int i = 0; i < n; i++) {
            int spell = spells[i];
            // 找第一个 >= (spell + 1) 的位置，即 upper bound
            int left = 0, right = m;
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (required[mid] <= spell) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }
            ans[i] = left; // left 是第一个 > spell 的位置，所以 <= spell 的数量是 left
        }
        
        return ans;
    }
}