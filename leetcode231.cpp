/*
 * @Author: thevoid3301
 * @Date: 2024-05-06 20:42:39
 * @Description: Maybe the test
 */
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n > 0 && !(n & (n - 1))){
            return true;
        }else{
            return false;
        }
    }
};