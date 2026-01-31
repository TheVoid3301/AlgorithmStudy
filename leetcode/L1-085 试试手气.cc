#include<iostream>
#include<vector>
using namespace std;
 
void solve(){
    vector<int> d(6) ;
    int st[6][7];
    for (int i = 0; i < 6; ++i) cin >> d[i];
    int n;
    cin >> n;
    for (int i = 0; i < 6; ++i) {
        cout << (d[i] <=6 - n ? 6 - n + 1 : 6 - n);
        if (i < 5) cout << " ";
    }
}
 
int main(){
	int t = 1;
	// cin >> t;
	while(t --)
	solve();
	return 0;
}