class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int, int> m;
        for (auto &i : nums) {
            m[i]++;
        }
        int res = 0;
        for (auto &i : m) {
            res = max(res, i.second);
        }
        int k = 0;
        for (auto &i : m) {
            if (i.second == res) {
                k += i.second;
            }
        }
        return k;
    }
};