/*
 * @Author: thevoid3301
 * @Date: 2024-05-03 20:45:10
 * @Description: Maybe the test
 */
#include <bits/stdc++.h>
using namespace std;
int main(){
    double r1, r2;
    cin >> r1 >> r2;
    cout << fixed << setprecision(2) << 1 / (1 / r1 + 1 / r2);
    return 0;
}