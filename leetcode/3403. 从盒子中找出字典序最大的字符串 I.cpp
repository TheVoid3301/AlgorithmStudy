class Solution {
public:
    string answerString(string s, int k) {
        if (k == 1) {
            return s;
        }
        int n = s.length();
        string ans;
        for (int i = 0; i < n; i++) {
            ans = max(ans, s.substr(i, n - max(k - 1, i)));
        }
        return ans;
    }
};