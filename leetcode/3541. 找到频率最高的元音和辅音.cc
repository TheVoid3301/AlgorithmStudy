class Solution {
public:
    int maxFreqSum(string s) {
        map<char, int> m, p;
        for (auto i : s)
        {
            if (i == 'a' || i == 'e' || i == 'i' || i == 'o' || i == 'u')
            {
                m[i]++;
            }
            else
            {
                p[i]++;
            }
        }
        int res1 = 0, res2 = 0;
        for (auto i : m) 
        {
            res1 = max(res1, i.second);
        }
        for (auto i : p)
        {
            res2 = max(res2, i.second);
        }
        return res1 + res2;
    }
};