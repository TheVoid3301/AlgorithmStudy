/*
 * @Description: 
 * @Auther: thevoid3301
 * @Date: 2025-07-18 23:52:47
 * @LastEditors: thevoid3301
 * @LastEditTime: 2025-07-19 00:06:27
 * @FilePath: \luogu\lanqiao14.1.cc
 */
#include <bits/stdc++.h>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<long long> v(4);
    for (int i = 1; i <= 2023; ++i) {
        string s = to_string(i);
        for (auto x : s) {
            if (x == '2') {
                v[0]++;
                v[2] += v[1];
            } else if (x == '0') {
                v[1] += v[0];
            } else if (x == '3') {
                v[3] += v[2];
            }
        }
    }
    cout << v[3] << endl;
    return 0;
}