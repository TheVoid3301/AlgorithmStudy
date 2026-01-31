#include<iostream>
 
using namespace std;
 
void solve(){
	int a , b ;
    cin >> a >> b;
    int a1 = a , b1 = b;
    int c = 0 , d = 0 ;
    while(a1)
    {
        c += a1 % 10;
        a1 /= 10;
    }
    while(b1)
    {
        d += b1 % 10;
        b1 /= 10;
    }
    bool op1 = (a % d == 0 ? 1 : 0) ;
    bool op2 = (b % c == 0 ? 1 : 0);
 
    if(op1 && !op2)
        cout << "A" ;
    else if(!op1 && op2)
        cout << "B";
    else
        cout << (a > b ? "A" : "B");
    cout << '\n';
}
 
int main(){
	int t = 1;
	cin >> t;
	while(t --)
	solve();
	return 0;
}
 