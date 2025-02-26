/*
 * @lc app=leetcode.cn id=1472 lang=cpp
 *
 * [1472] 设计浏览器历史记录
 */

// @lc code=start
class BrowserHistory {
public:
    BrowserHistory(string homepage) {
        this->urls.push_back(homepage);
        this->currIndex = 0;
    }
    
    void visit(string url) {
        while (urls.size() > currIndex + 1) {
            urls.pop_back();
        }
        urls.push_back(url);
        this->currIndex++;
    }
    
    string back(int steps) {
        currIndex  = max(currIndex - steps, 0);
        return urls[currIndex];
    }
    
    string forward(int steps) {
        currIndex = min(currIndex + steps, int(urls.size() - 1));
        return urls[currIndex];
    }
private:
    vector<string> urls;
    int currIndex;
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
// @lc code=end

