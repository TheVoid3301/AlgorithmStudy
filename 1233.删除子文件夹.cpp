/*
 * @lc app=leetcode.cn id=1233 lang=cpp
 *
 * [1233] 删除子文件夹
 */

// @lc code=start
#include <cstddef>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        unordered_map<string, int> s;
        for (auto i : folder) {
            s.insert({i, 1});
        }
        for (auto i : folder) {
            vector<string> head;
            int n = i.find( "/", 1);
            while (n != string::npos) {
                head.push_back(i.substr(0, n));
                n = i.find( "/", n + 1);
            }
            for (auto k : head) {
                if (s.count(k)) {
                    s[i] = 0;
                    break;
                }
            }
        }
        vector<string> res;
        for (auto i : s) {
            if (i.second == 1) {
                res.push_back(i.first);
            }
        }
        return res;
    }
};
// @lc code=end

