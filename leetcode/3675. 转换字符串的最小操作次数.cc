#include <string>
#include <map>
using namespace std;

class Solution {
public:
    int minOperations(string s) {
        char minChar = 'z' + 1;
        for (auto &i : s) {
            if (i < minChar && i != 'a') {
                minChar = i;
            }
        }
        if (minChar == 'z' + 1) {
            return 0;
        }
        return 'z' - minChar + 1;
    }
};