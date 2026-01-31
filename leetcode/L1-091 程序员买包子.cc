#include<iostream>
 
using namespace std;
 
void solve(){
    string x;
    int n , m , k;
    cin >> n >> x >> m >> k;
    if(k == n)
        cout << "mei you mai " <<  x <<" de";
    else if(k == m)
        cout << "kan dao le mai " << x <<" de";
    else 
        cout << "wang le zhao mai " << x <<" de";
}
 
int main(){
	int t = 1;
	// cin >> t;
	while(t --)
	solve();
	return 0;
}