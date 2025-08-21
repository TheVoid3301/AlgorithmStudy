/*
 * @Description: 
 * @Auther: thevoid3301
 * @Date: 2025-07-19 00:10:14
 * @LastEditors: thevoid3301
 * @LastEditTime: 2025-07-19 00:27:47
 * @FilePath: \luogu\lanqiao14.2.cc
 */

#include <cmath>
#include <iostream>

using namespace std;

bool iszhi(long long x) {
    for (long long i = 2; i <= (long long)sqrt(x); ++i) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

bool isres(long long x) {
    int k = 0;
    for (long long i = 2; i <= (long long) sqrt(x); ++i) {
        if (x % i == 0) {
            if (!iszhi(i)) {
                return false;
            }
            k++;
            if (k > 2) {
                return false;
            }
        }
    }
    return k == 2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long res = 0;
    for (long long i = 2333; i <= 23333333333333; ++i) {
        if ((long long)(sqrt(i) * sqrt(i)) != i) {
            continue;
        }
        if (isres(i)) {
            res++;
        }
    }
    cout << res;
    return 0;
}