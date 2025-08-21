class Solution {
    public int[] replaceElements(int[] arr) {
        int maxn = 0, start = 0;
        while (start < arr.length - 1) {
            maxn = start + 1;
            for (int i = start + 1; i < arr.length; ++i) {
                if (arr[i] >= arr[maxn]) {
                    maxn = i;
                }
            }
            for (int i = start; i < maxn; ++i) {
                arr[i] = arr[maxn];
            }
            start = maxn;
        }
        arr[arr.length - 1] = -1;
        return arr;
    }
}