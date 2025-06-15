#include <string>
#include <cctype>
using namespace std;

class Solution {
public:
    string generateTag(string caption) {
        string res = "#";
        
        // 去除首尾空格
        while (!caption.empty() && caption[0] == ' ') {
            caption.erase(caption.begin());
        }
        while (!caption.empty() && caption.back() == ' ') {
            caption.erase(caption.end() - 1);
        }

        for (int j = 0; j < caption.size(); ++j) {
            caption[j] = tolower(caption[j]);
        }
        
        // 处理每个单词
        size_t i = 0;
        size_t s = 0;
        while ((i = caption.find(' ', i)) != string::npos) {
            //确保不是连续的空格
            if (i > s) {  
                string t = caption.substr(s, i - s);
                t[0] = toupper(t[0]);
                res += t;
            }
            s = i + 1;
            i++;
        }

        if (s < caption.size()) {
            string t = caption.substr(s);
            t[0] = toupper(t[0]);
            res += t;
        }

        res[1] = tolower(res[1]);

        for (i = 1; i < res.size(); ++i) {
            if (!isalpha(res[i])) {
                res.erase(i, 1);
            }
        }
        
        return res.substr(0, 100);
    }
};