class Solution {
public:
    long long bowlSubarrays(vector<int>& nums) {
        int ans = 0;
        stack<int> st;
        for (int x : nums) {
            while (!st.empty() && st.top() < x) {
                st.pop();
                if (!st.empty()) {
                    ans++;
                }
            }
            st.push(x);
        }
        return ans;
    }
};