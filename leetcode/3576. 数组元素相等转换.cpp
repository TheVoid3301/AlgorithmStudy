class Solution {
public:
    bool canMakeEqual(vector<int>& nums, int k) {
        auto check = [&](int target) -> bool {
            int left = k;
            int mul = 1;
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] * mul == target) {
                    mul = 1; // 不操作，下一个数不用乘 -1
                    continue;
                }
                if (left == 0 || i + 1 == nums.size()) {
                    return false;
                }
                left--;
                mul = -1; // 操作，下一个数要乘 -1
            }
            return true;
        };
        return check(-1) || check(1);
    }
};