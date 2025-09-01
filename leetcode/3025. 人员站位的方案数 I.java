import java.util.Arrays;

class Solution {
    public int numberOfPairs(int[][] points) {
        // 排序：按 x 升序，x 相同时按 y 降序
        Arrays.sort(points, (a, b) -> {
            if (a[0] != b[0]) {
                return Integer.compare(a[0], b[0]); // x 升序
            }
            return Integer.compare(b[1], a[1]);    // y 降序
        });

        int ans = 0;

        for (int i = 0; i < points.length; i++) {
            int y1 = points[i][1];
            int max_y = Integer.MIN_VALUE; // 记录从点 i 向右看时，当前最高点的 y 值

            for (int j = i + 1; j < points.length; j++) {
                int y2 = points[j][1];

                // 条件：y2 <= y1（在下方或等高）且 y2 > max_y（未被前面的点挡住）
                if (y2 <= y1 && y2 > max_y) {
                    max_y = y2;
                    ans++;
                }
            }
        }

        return ans;
    }
}