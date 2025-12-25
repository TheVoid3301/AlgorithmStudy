#include <bits/stdc++.h>
using namespace std;

int main() {
    map<int, double, greater<int>> polynomial;
    int a, n;
    double b;
    
    for (int i = 0; i < 2; ++i) {
        cin >> n;
        for (int j = 0; j < n; ++j) {
            cin >> a >> b;
            polynomial[a] += b;
            
            // 如果系数为0，删除该项
            if (fabs(polynomial[a]) < 1e-8) {
                polynomial.erase(a);
            }
        }
    }
    
    // 再次检查，确保没有系数为0的项
    for (auto it = polynomial.begin(); it != polynomial.end(); ) {
        if (fabs(it->second) < 1e-8) {
            it = polynomial.erase(it);
        } else {
            ++it;
        }
    }
    
    // 输出
    cout << polynomial.size();
    for (auto& item : polynomial) {
        printf(" %d %.1lf", item.first, item.second);
    }
    cout << endl;
    
    return 0;
}