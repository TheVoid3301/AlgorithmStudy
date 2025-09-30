class Solution:
    def numWaterBottles(self, numBottles: int, numExchange: int) -> int:
        if numBottles < numExchange:
            return numBottles
        ans = numBottles
        empty = numBottles
        while empty >= numExchange:
            newBottles = empty // numExchange
            ans += newBottles
            empty = empty % numExchange + newBottles
        return ans