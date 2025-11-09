class Solution {
public:
    int countOperations(int num1, int num2) {
        int res = 0;   // 相减操作的总次数
        while (num1 && num2) {
            // 每一步辗转相除操作
            res += num1 / num2;
            num1 %= num2;
            swap(num1, num2);
        }
        return res;
    }
};
