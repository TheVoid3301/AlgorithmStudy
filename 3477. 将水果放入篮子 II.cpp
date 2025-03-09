class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int res = fruits.size();
        for (int i = 0; i < fruits.size(); ++i)
        {
            for (int j = 0; j < baskets.size(); ++j)
            {
                if (baskets[j] >= fruits[i])
                {
                    baskets[j] = 0;
                    res--;
                    break;
                }
            }
        }
        return res;
    }
};