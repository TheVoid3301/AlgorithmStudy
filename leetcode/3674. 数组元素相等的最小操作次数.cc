#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        set<int> s;
        for (auto &i : nums) {
            s.insert(i);
        }
        return s.size() == 1 ? 0 : 1;
    }
};