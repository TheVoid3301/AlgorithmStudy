class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        unordered_set<int> nums;   // 目标偶数集合
        int n = digits.size();
        // 遍历三个数位的下标
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < n; ++j){
                for (int k = 0; k < n; ++k){
                    // 判断是否满足目标偶数的条件
                    if (i == j || j == k || i == k){
                        continue;
                    }
                    int num = digits[i] * 100 + digits[j] * 10 + digits[k];
                    if (num >= 100 && num % 2 == 0){
                        nums.insert(num);
                    }
                }
            }
        }
        // 转化为升序排序的数组
        vector<int> res;
        for (const int num: nums){
            res.push_back(num);
        }
        sort(res.begin(), res.end());
        return res;
    }
};