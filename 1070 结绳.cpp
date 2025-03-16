#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<float> res(n);
    for (int i = 0; i < n; ++i) {
        cin >> res[i];
    }
    sort(res.begin(), res.end());
    while (res.size() > 1) {
        res[0] = (res[0] + res[1]) / 2;
        res.erase(res.begin() + 1);
    }
    cout << floor(res[0]);
}