#include<iostream>
#include<cstring>
 
using namespace std;
int mp[10][10] , a[10] , b[10];
void solve(){
    bool isLegal = 0; 
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            cin >> mp[i][j];
        }
    }
 
    // 检查每行和每列的数字是否重复
    for (int i = 1; i <= 9; i++) {
        memset(a , 0 , sizeof a);
        memset(b , 0 , sizeof b);
        for (int j = 1; j <= 9; j++) {
            a[mp[i][j]]++;
            b[mp[j][i]]++;
        }
 
        for (int k = 1; k <= 9; k++) {
            if (a[k] == 0 || a[k] > 1 || b[k] == 0 || b[k] > 1) {
                isLegal = 1;
                break;
            }
        }
        if (isLegal == 1) break;
    }
    // 检查每个3x3宫格的数字是否重复
    for (int x = 1; x <= 7; x += 3) {
        for (int y = 1; y <= 7; y += 3) {
            memset(a , 0 , sizeof a);
            for (int i = x; i < x + 3; i++) {
                for (int j = y; j < y + 3; j++) {
                    a[mp[i][j]]++;
                }
            }
            for (int k = 1; k <= 9; k++) {
                if (a[k] == 0 || a[k] > 1) {
                    isLegal = 1;
                    break;
                }
            }
            if (isLegal == 1) break;
        }
        if (isLegal == 1) break;
    }
    cout << (isLegal == 1 ? "0" : "1") << '\n';
 
}
 
int main(){
	int t = 1;
	cin >> t;
	while(t --)
	solve();
	return 0;
}
 