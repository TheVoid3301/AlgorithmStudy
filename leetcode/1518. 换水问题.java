class Solution {
    public int numWaterBottles(int numBottles, int numExchange) {
        if (numBottles < numExchange) {
            return numBottles;
        }
        int ans = numBottles;
        int empty = numBottles;
        while (empty >= numExchange) {
            int newBottles = empty / numExchange;
            ans += newBottles;
            empty = empty % numExchange + newBottles;
        }
        return ans;
    }
}