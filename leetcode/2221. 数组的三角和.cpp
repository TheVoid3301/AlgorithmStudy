#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int triangularSum(vector<int>& nums) {
        queue<int> q;
        for (int num : nums) {
            q.push(num);
        }
        while (q.size() > 1) {
            int n = q.size();
            for (int i = 0; i < n - 1; ++i) {
                int a = q.front();
                q.pop();
                int b = q.front();
                q.push((a + b) % 10);
                if (i == n - 2) {
                    q.pop();
                }
            }
        }
        return q.front();
    }
};