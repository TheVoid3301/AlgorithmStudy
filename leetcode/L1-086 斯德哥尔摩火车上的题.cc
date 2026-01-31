#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
 
string so(string a)
{
    string s;
    for (int i = 1; i < a.size(); i++) {
      if (a[i] % 2 == a[i-1] % 2) {
        s += max(a[i], a[i-1]);
      }
    }
    return s;
}
 
void solve(){
    string s , a;
    cin >> s >> a;
    s = so(s);
    a = so(a);
    if(s == a)
        cout <<s;
    else
        cout << s <<'\n' << a;
}
 
int main(){
	int t = 1;
	// cin >> t;
	while(t --)
	solve();
	return 0;
}