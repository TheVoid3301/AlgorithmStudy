#include <bits/stdc++.h>
using namespace std;
int main(){
    int hash[10000] = {0};
    int l, m, a, b, k = 0;
    cin >> l >> m;
    for(int i = 0; i < m; ++i){
        cin >> a >> b;
        for(int j = a; j <= b; ++j){
            if(hash[j] == 0){
                hash[j] = 1;
            }
        }
    }
    for(int i = 0; i <= l; ++i){
        if(hash[i] == 1){
            ++k;
        }
    }
    cout << l - k + 1;
    return 0;
}