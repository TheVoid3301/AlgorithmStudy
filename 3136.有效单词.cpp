/*
 * @lc app=leetcode.cn id=3136 lang=cpp
 *
 * [3136] 有效单词
 */

// @lc code=start
#include <cctype>
class Solution {
public:
    bool isValid(string word) {
        if (word.size() < 3) {
            return false;
        }
        int yuan = 0, fu = 0;
        for(auto &i : word) {
            if (!isalpha(i) && !isdigit(i)) {
                return false;
            }
            if (isalpha(i)) {
                i = std::tolower(i);
                if (i == 'a' || i == 'e' || i == 'i'
                || i == 'o' || i == 'u') {
                    yuan = 1;
                } else {
                    fu = 1;
                }
            }
        }
        if (!yuan || !fu) {
            return false;
        }
        return true;
    }
};
// @lc code=end

