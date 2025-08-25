class Solution {
    public int areaOfMaxDiagonal(int[][] dimensions) {
        int max_len = 0;
        int max_area = 0;
        for (int[] i : dimensions) {
            if (i[0] * i[0] + i[1] * i[1] > max_len) {
                max_len = i[0] * i[0] + i[1] * i[1];
                max_area = i[0] * i[1];
            } else if (i[0] * i[0] + i[1] * i[1] == max_len) {
                max_area = Math.max(max_area, i[0] * i[1]);
            }
        }
        return max_area;
    }
}