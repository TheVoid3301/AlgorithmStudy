class Solution {
public:
    string dynamicPassword(string password, int target) {
        string res;
        res = password.substr(target);
        res += password.substr(0, target);
        return res;
    }
};