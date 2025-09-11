class Solution {
public:
    bool doesAliceWin(string s) {
        int res = 0;
        for (auto i : s) {
            if (i == 'a' || i == 'e' || i == 'i' || i == 'o' || i == 'u') {
                res++;
            }
        }
        if (res == 0) {
            return false;
        }
        return true;
    }
};