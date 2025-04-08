class Solution {
public:
    bool check(unordered_map<int, int> m) {
        for (auto i : m) {
            if (i.second > 1) {
                return false;
            }
        }
        return true;
    }

    int minimumOperations(vector<int>& nums) {
        unordered_map<int, int> m;
        for (auto i : nums) {
            if (m.count(i)) {
                m[i]++;
            } else {
                m[i] = 1;
            }
        }
        int res = 0;
        while (!check(m)) {
            for (int i = 0; i < 3 && nums.size() > 0; ++i) {
                m[nums[0]]--;
                nums.erase(nums.begin());
            }
            ++res;
        }
        return res;
    }
};