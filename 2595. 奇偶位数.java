class Solution {
    public int[] evenOddBit(int n) {
        boolean f = true;
        int even = 0, odd = 0;
        while (n > 0) {
            if (n % 2 == 1 && f) {
                even++;
            } else if (n % 2 == 1 && !f) {
                odd++;
            }
            n /= 2;
            f = !f;
        }
        return new int[]{even, odd};
    }
}