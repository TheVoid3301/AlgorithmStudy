/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

// @lc code=start
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>map;
        vector<int>result;
        for(auto num:nums){
            map[num]++;
        }
        vector<pair<int,int>>vec(map.begin(),map.end());
        sort(vec.begin(),vec.end(),[](pair<int,int>&a,pair<int,int>&b){
            return a.second>b.second;
        });
        for(auto pair:vec){
            if(k>0){
                result.push_back(pair.first);   
            }
            k--;
        }
        return result;
    }
};
// @lc code=end

