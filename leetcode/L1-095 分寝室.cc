#include<iostream>
#include<cmath>
using namespace std;
 
void solve(){
	int a , b , c;
    cin >> a >> b >> c;
    int l = -1e8, r = 1e8, minv = 1e9;
    for(int i = 2 ; i < min({a , b , c}); i ++)
        if(a % i == 0 && b % (c - i) == 0 )
        {
            if(abs(r - l) < minv)
            {
                l = i ;
                r = c - i ;
                minv = abs(r - l);
            }
        }
    if(minv == 1e9)
        cout << "No Solution";
    else
        cout << l <<' ' << r ;
}
 
int main(){
	int t = 1;
	// cin >> t;
	while(t --)
	solve();
	return 0;
}
 