#include<iostream>
using namespace std;
 
void solve(){
    int n , m , k;
    cin >> n >> m;
    int res = 0;
    for (int i = 0; i < m; ++i) {
        cin >> k;
        res += k;
    }
    int minv = res - (m - 1) * n;
    if (minv < 0) {
        minv = 0;
    }
    cout << minv;
}
 
int main(){
	int t = 1;
	// cin >> t;
	while(t --)
	solve();
	return 0;
}
 