class Solution {
    public int hIndex(int[] citations) {
        if (citations.length == 1) {
            return citations[0] > 0 ? 1 : 0;
        }
        for (int i = citations.length; i >= 1; i--) {
            if (citations[citations.length - i] >= i) {
                return i;
            }
        }
        return 0;
    }
}