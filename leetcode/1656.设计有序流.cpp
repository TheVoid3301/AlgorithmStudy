/*
 * @lc app=leetcode.cn id=1656 lang=cpp
 *
 * [1656] 设计有序流
 */

// @lc code=start
class OrderedStream {
private:
    int ptr;
    vector<pair<int, string>> stream;
public:
    OrderedStream(int n) {
        this -> ptr = 1;
    }
    
    vector<string> insert(int idKey, string value) {
        vector<string> res = {};
        vector<pair<int, string>>::iterator it;
        if (stream.size() == 0) {
            stream.push_back(make_pair(idKey, value));
        } else {
            it = find_if(stream.begin(), stream.end(), [idKey](pair<int, string>& t){
                return t.first > idKey;
            });
            stream.insert(it, make_pair(idKey, value));
        }
        for (int i = 0; i < stream.size(); ++i) {
            if (stream[i].first == this -> ptr) {
                res.push_back(stream[i].second);
                ptr = stream[i].first + 1;
                for (int j = i + 1; j < stream.size(); ++j) {
                    if (stream[j].first - stream[j - 1].first == 1) {
                        res.push_back(stream[j].second);
                        ptr = stream[j].first + 1;
                    } else {
                        break;
                    }
                }
                break;
            }
        }
        return res;
    }
};
/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */
// @lc code=end

