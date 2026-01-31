#include<iostream>
 
using namespace std;
 
void solve(){
	int n , m ;
	cin >> n >>m ;
	int sum = 1;
    for(int i = 2; i <= n + m ; i ++) sum *= i;
    cout << sum;
}
 
int main(){
	int t = 1;
	// cin >> t;
	while(t --)
	solve();
	return 0;
}