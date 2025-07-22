/*
 * @Description: 
 * @Auther: thevoid3301
 * @Date: 2025-07-22 23:41:09
 * @LastEditors: thevoid3301
 * @LastEditTime: 2025-07-23 00:05:45
 * @FilePath: \luogu\数三角.cc
 */

#include <iostream>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;
    map<int, int> m;
    int a, b;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        m[a] = b;
    }
    int res = 0;
    for (auto i = ++m.begin(); i != m.end(); ++i) {
        for (auto j = m.begin(); j != i; ++j) {
            auto k = i;
            for (++k; k != m.end(); ++k) {
                if (((i->first - j->first) * (i->first - j->first) + (i->second - j->second) * (i->second - j->second))
                == ((j->first - k->first) * (j->first - k->first) + (j->second - k->second) * (j->second - k->second))
                || ((i->first - j->first) * (i->first - j->first) + (i->second - j->second) * (i->second - j->second))
                == ((i->first - k->first) * (i->first - k->first) + (i->second - k->second) * (i->second - k->second))
                || ((i->first - k->first) * (i->first - k->first) + (i->second - k->second) * (i->second - k->second))
                == ((j->first - k->first) * (j->first - k->first) + (j->second - k->second) * (j->second - k->second))) {
                    res++;
                }
                
            }
        }
    }
    cout << res;
    return 0;
}