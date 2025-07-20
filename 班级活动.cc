/*
 * @Description: 
 * @Auther: thevoid3301
 * @Date: 2025-07-20 22:10:57
 * @LastEditors: thevoid3301
 * @LastEditTime: 2025-07-20 22:39:44
 * @FilePath: \luogu\班级活动.cc
 */

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    unordered_map<int, int> v;
    int t;
    for (int i = 0; i < n; ++i) {
        cin >> t;
        v[t]++;
    }

    int res = 0;

    int once = 0;
    int more = 0;

    for (auto &i : v) {
        if (i.second > 2) {
            more += (i.second - 2);
        } else if (i.second == 1) {
            once++;
        }
    }

    if (more > once) {
        res = more;
    } else {
        res = more + (once - more) / 2;
    }

    cout << res;
    
    return 0;
}