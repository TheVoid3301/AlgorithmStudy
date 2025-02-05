class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char, int> m;
        for (auto i : s)
        {
            m[i]++;
        }
        int evenNum = INT_MAX, oddNum = 0;
        for (auto i : m)
        {
            if (i.second % 2 == 0)
            {
                evenNum = min(evenNum, i.second);
            }
            else
            {
                oddNum = max(oddNum, i.second);
            }
        }
        return oddNum - evenNum;
    }
};