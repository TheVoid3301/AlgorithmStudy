#include <bits/stdc++.h>
using namespace std;
int main(){
    int a, b, max = 0, maxd = 0;
    for(int i = 1; i <= 7; ++i){
        cin >> a >> b;
        if(a + b > max && a + b > 8){
            maxd = i;
            max = a + b;
        }
    }
    cout << maxd;
    return 0;
}