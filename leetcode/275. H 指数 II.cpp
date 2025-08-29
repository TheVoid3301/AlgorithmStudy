class Solution {
public:
    int hIndex(vector<int>& citations) {
        if (citations.size() == 1) {
            return citations[0] >= 1 ? 1 : 0;
        }
        for (int i = citations.size(); i > 0; i--) {
            if (citations[(int)citations.size() - i] >= i) {
                return i;
            }
        }
        return 0;
    }
};