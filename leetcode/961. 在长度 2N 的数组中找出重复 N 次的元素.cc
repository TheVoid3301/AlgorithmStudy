class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size();
        mt19937 gen{random_device{}()};
        uniform_int_distribution<int> dis(0, n - 1);

        while (true) {
            int x = dis(gen), y = dis(gen);
            if (x != y && nums[x] == nums[y]) {
                return nums[x];
            }
        }
    }
};