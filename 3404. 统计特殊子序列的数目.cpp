class Solution {
public:
    void huisu(vector<int>& nums, int start, vector<int> &p, long long &res) {
        if (p.size() == 4) {
            if (nums[p[0]] * nums[p[2]] == nums[p[1]] * nums[p[3]]) {
                res++;
            }
            return ;
        }
        for (int i = start; i < nums.size(); ++i) {
            p.push_back(i);
            huisu(nums, i + 2, p, res);
            p.pop_back();
        }
    }
    long long numberOfSubsequences(vector<int>& nums) {
        vector<int> p;
        long long res = 0;
        huisu(nums, 0, p, res);
        return res;
    }
};