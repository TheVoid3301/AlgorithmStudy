#include<iostream>
 
using namespace std;
 
void solve(){
    int n , m;
    cin >> n >> m;
    int nm = n + m;
    cout << nm - 16 <<'\n';
    cout << nm - 3 <<'\n';
    cout << nm - 1 <<'\n';
    cout << nm;
}
 
int main(){
	int t = 1;
	// cin >> t;
	while(t --)
	solve();
	return 0;
}