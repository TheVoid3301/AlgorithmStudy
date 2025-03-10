/*
 * @lc app=leetcode.cn id=210 lang=cpp
 *
 * [210] 课程表 II
 */

// @lc code=start
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ru(numCourses, 0);
        vector<vector<bool>> edge(numCourses, vector<bool>(numCourses, false));
        for (auto j : prerequisites)
        {
            edge[j[1]][j[0]] = true;
        }
        for (int i = 0; i < prerequisites.size(); ++i)
        {
            ru[prerequisites[i][0]]++;
        }
        stack<int> s;
        vector<int> res;
        for (int i = 0; i < ru.size(); ++i)
        {
            if (ru[i] == 0)
            {
                s.push(i);
                ru[i] = -1;
            }
        }
        while (!s.empty())
        {
            res.push_back(s.top());
            for (int i = 0; i < numCourses; ++i)
            {
                if (edge[s.top()][i] == true && ru[i] >= 0)
                {
                    ru[i]--;
                }
            }
            s.pop();
            for (int i = 0; i < numCourses; ++i)
            {
                if (ru[i] == 0)
                {
                    s.push(i);
                    ru[i] = -1;
                }
            }
        }
        if (res.size() < numCourses)
        {
            return {};
        }
        else
        {
            return res;
        }
    }
};
// @lc code=end

