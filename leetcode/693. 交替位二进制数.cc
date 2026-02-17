class Solution {
public:
    bool hasAlternatingBits(int n) {
        int a = n % 2;
        n /= 2;
        while (n) {
            if (a != n % 2) {
                a = n % 2;
                n /= 2;
            } else {
                return false;
            }
        }
        return true;
    }
};