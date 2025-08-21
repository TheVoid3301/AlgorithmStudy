/*
 * @lc app=leetcode.cn id=433 lang=cpp
 *
 * [433] 最小基因变化
 */

// @lc code=start
class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        int t = 0;
        vector<string> copyBank = bank;
        auto i = find(copyBank.begin(), copyBank.end(), startGene);
        if (i != copyBank.end()) 
        {
            copyBank.erase(i);
        }
        queue<string> q;
        q.push(startGene);
        while (!q.empty()) 
        {
            int l = q.size();
            while (l) 
            {
                if (q.front() == endGene) 
                {
                    return t;
                }
                for (int i = 0; i < 8; ++i) 
                {
                    string s = q.front();
                    s[i] = 'A';
                    auto k = find(copyBank.begin(), copyBank.end(), s);
                    if (k != copyBank.end()) 
                    {
                        q.push(s);
                        copyBank.erase(k);
                    }
                    s[i] = 'C';
                    k = find(copyBank.begin(), copyBank.end(), s);
                    if (k != copyBank.end()) 
                    {
                        q.push(s);
                        copyBank.erase(k);
                    }
                    s[i] = 'G';
                    k = find(copyBank.begin(), copyBank.end(), s);
                    if (k != copyBank.end()) 
                    {
                        q.push(s);
                        copyBank.erase(k);
                    }
                    s[i] = 'T';
                    k = find(copyBank.begin(), copyBank.end(), s);
                    if (k != copyBank.end()) 
                    {
                        q.push(s);
                        copyBank.erase(k);
                    }
                }
                q.pop() ;
                --l;
            }
            ++t;
        }
        return -1;
    }
};
// @lc code=end

