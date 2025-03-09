class Solution {
public:
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<tuple<int, int, int>> a(n);
        for (int i = 0; i < n; i++) {
            a[i] = {nums1[i], nums2[i], i};
        }
        ranges::sort(a);

        vector<long long> ans(n);
        priority_queue<int, vector<int>, greater<>> pq;
        long long s = 0;
        // 分组循环模板
        for (int i = 0; i < n;) {
            int start = i;
            int x = get<0>(a[start]);
            // 找到所有相同的 nums1[i]，这些数的答案都是一样的
            while (i < n && get<0>(a[i]) == x) {
                ans[get<2>(a[i])] = s;
                i++;
            }
            // 把这些相同的 nums1[i] 对应的 nums2[i] 入堆
            for (int j = start; j < i; j++) {
                int y = get<1>(a[j]);
                s += y;
                pq.push(y);
                if (pq.size() > k) {
                    s -= pq.top();
                    pq.pop();
                }
            }
        }
        return ans;
    }
};