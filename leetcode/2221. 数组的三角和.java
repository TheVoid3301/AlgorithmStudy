class Solution {
    public int triangularSum(int[] nums) {
        Queue<Integer> queue = new LinkedList<>();
        for (int num : nums) {
            queue.offer(num);
        }
        while (queue.size() > 1) {
            int size = queue.size();
            for (int i = 0; i < size - 1; i++) {
                int a = queue.poll();
                int b = queue.peek();
                queue.offer((a + b) % 10);
                if (i == size - 2) {
                    queue.poll();
                }
            }
        }
        return queue.poll();
    }
}