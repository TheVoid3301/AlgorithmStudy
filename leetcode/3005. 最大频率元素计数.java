class Solution {
    public int maxFrequencyElements(int[] nums) {
        HashMap<Integer, Integer> m = new HashMap<>();
        for (int n : nums) {
            m.put(n, m.getOrDefault(n, 0) + 1);
        }
        int res = 0;
        for (int v : m.values()) {
            res = Math.max(res, v);
        }
        int k = 0;
        for (int v : m.values()) {
            if (v == res) {
                k += res;
            }
        }
        return k;
    }
}