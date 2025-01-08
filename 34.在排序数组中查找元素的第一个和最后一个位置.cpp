class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2, -1);
        int i = 0, j = nums.size() - 1;
        while(i < nums.size())
        {
            if(nums[i] == target)
            {
                res[0] = i;
                break;
            }
            ++i;
        }
        while(j >= 0)
        {
            if(nums[j] == target)
            {
                res[1] = j;
                break;
            }
            --j;
        }
        return res;
    }
};