#include<iostream>
 
using namespace std;
 
void solve(){
    int n , v;
    cin >> n >> v;
    cout << n / v;
}
 
int main(){
	int t = 1;
	// cin >> t;
	while(t --)
	solve();
	return 0;
}