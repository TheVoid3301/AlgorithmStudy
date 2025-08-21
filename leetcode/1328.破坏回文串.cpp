/*
 * @lc app=leetcode.cn id=1328 lang=cpp
 *
 * [1328] 破坏回文串
 */

// @lc code=start
class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.size();
        if (n == 1) {
            return "";
        }
        for (int i = 0; i * 2 + 1 < n; i++) {
            if (palindrome[i] != 'a') {
                palindrome[i] = 'a';
                return palindrome;
            }
        }
        palindrome.back()++;
        return palindrome;
    }
};
// @lc code=end

