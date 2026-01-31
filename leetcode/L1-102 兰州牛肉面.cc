#include<iostream>
#include<vector>
using namespace std;
 
void solve(){
	int n;
    cin >> n;
    vector<double> p(n);
    for (auto &i : p)cin >> i;
 
    vector<int> c(n, 0);
    int t, b;
    double tr = 0;
 
    while (true) {
        cin >> t;
        if (t == 0) break;
        cin >> b;
        c[t - 1] += b;
        tr += p[t - 1] * b;
    }
 
    for (int i = 0; i < n; ++i) cout << c[i] << endl;
    printf("%.2f" , tr);
}
 
int main(){
	int t = 1;
	// cin >> t;
	while(t --)
	solve();
	return 0;
}
 