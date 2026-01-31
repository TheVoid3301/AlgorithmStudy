#include<iostream>
 
using namespace std;
 
void solve(){
    int n, m, a, b;
    cin >> n >> m >> a >> b;
 
    bool op1 = a >= n || (a < n && b >= m);
    bool op2 = b >= n || (b < n && a >= m);
 
    cout << a << "-" << (op1 ? "Y" : "N") << " " 
         << b << "-" << (op2 ? "Y" : "N") << endl;
 
    if (op1 && op2) {
        if (a < n && b >= m) {
            cout << "qing 2 zhao gu hao 1";
        } else if (b < n && a >= m) {
            cout << "qing 1 zhao gu hao 2";
        } else {
            cout << "huan ying ru guan";
        }
    } else if (!op1 && !op2) {
        cout << "zhang da zai lai ba";
    } else if (op1) {
        cout << "1: huan ying ru guan";
    } else if (op2) {
        cout << "2: huan ying ru guan";
    }
}
 
int main(){
	int t = 1;
	// cin >> t;
	while(t --)
	solve();
	return 0;
}