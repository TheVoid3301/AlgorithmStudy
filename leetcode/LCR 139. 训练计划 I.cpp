class Solution {
public:
    vector<int> trainingPlan(vector<int>& actions) {
        vector<int> res;
        for (auto i : actions) {
            if (i % 2 == 1) {
                res.insert(res.begin(), i);
            } else {
                res.push_back(i);
            }
        }
        return res;
    }
};