/*
 * @Author: thevoid3301
 * @Date: 2024-05-08 08:01:30
 * @Description: Maybe the test
 */
#include <bits/stdc++.h>
using namespace std;
int main(){
    int a, b, sum = 0;
    vector<int> p;
    for(int i = 0; i < 10; ++i){
        cin >> a;
        p.push_back(a);
    }
    cin >> b;
    b += 30;
    for(auto it = p.begin(); it != p.end(); ++it){
        if(*it <= b){
            ++sum;
        }
    }
    cout << sum;
    return 0;
}