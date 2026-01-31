#include<iostream>
 
using namespace std;
 
void solve(){
    int a , b , c;
    cin >> a >> b >> c;
    if(c == a * b)
        cout << "Lv Yan" << '\n';
    else if(c == a + b)
        cout << "Tu Dou" << '\n';
    else
        cout << "zhe du shi sha ya!" << '\n';
}
 
int main(){
	int t = 1;
	cin >> t;
	while(t --)
	solve();
	return 0;
}