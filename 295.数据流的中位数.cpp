/*
 * @lc app=leetcode.cn id=295 lang=cpp
 *
 * [295] 数据流的中位数
 */

// @lc code=start
class MedianFinder {
private:
    vector<int> v;
public:
    MedianFinder() {
        v.clear();
    }
    
    void addNum(int num) {
        auto it = lower_bound(v.begin(), v.end(), num);
        v.insert(it, num);
    }
    
    double findMedian() {
        if (v.size() % 2 == 0) {
            return 0.5 * (v[v.size() / 2] + v[v.size() / 2 - 1]);
        } else {
            return v[v.size() / 2];
        }
    }
};


/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end

