#include<iostream>
 
using namespace std;
const int N = 1e5 + 10;
int l[N] , r[N];
void solve(){
    int n , m , q;
    cin >> n >> m >> q ;
    int sum = 0;
    while(q --)
    {
        int t , c;
        cin >> t >> c;
        if(t)
            r[c] = 1;
        else
            l[c] = 1;
    }
    for(int i = 1 ;i <= n ; i++)
    {
        if(l[i])continue;
        for(int j = 1; j <= m ; j ++)
        {
            if(r[j])continue;
            sum ++;
        }
    }
    cout <<sum;
}
 
int main(){
	int t = 1;
	// cin >> t;
	while(t --)
	solve();
	return 0;
}