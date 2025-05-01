/*
 * @lc app=leetcode.cn id=2071 lang=cpp
 *
 * [2071] 你可以安排的最多任务数目
 */

// @lc code=start
class Solution {
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        int n = tasks.size(), m = workers.size();
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());
        
        auto check = [&](int mid) -> bool {
            int p = pills;
            // 工人的有序集合
            multiset<int> ws;
            for (int i = m - mid; i < m; ++i) {
                ws.insert(workers[i]);
            }
            // 从大到小枚举每一个任务
            for (int i = mid - 1; i >= 0; --i) {
                // 如果有序集合中最大的元素大于等于 tasks[i]
                if (auto it = prev(ws.end()); *it >= tasks[i]) {
                    ws.erase(it);
                }
                else {
                    if (!p) {
                        return false;
                    }
                    auto rep = ws.lower_bound(tasks[i] - strength);
                    if (rep == ws.end()) {
                        return false;
                    }
                    --p;
                    ws.erase(rep);
                }
            }
            return true;
        };
        
        int left = 1, right = min(m, n), ans = 0;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (check(mid)) {
                ans = mid;
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return ans;
    }
};
// @lc code=end

