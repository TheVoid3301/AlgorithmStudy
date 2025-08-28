class Solution {
    public long flowerGame(int n, int m) {
        return (long)(n / 2) * ((m + 1) / 2) + (long)((n + 1) / 2) * (m / 2);
    }
}