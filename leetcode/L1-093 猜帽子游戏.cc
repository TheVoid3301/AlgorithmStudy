#include<iostream>
#include<vector>
 
using namespace std;
 
void solve(){
    int n;
    cin >> n;
    vector<int>a(n);
    for(auto &i : a) cin >> i;
    int m;
    cin >> m;
    while(m --)
    {
        bool op = 1;
        int cnt = 0;
        for(int i = 0 ; i < n ; i ++)
        {
            int x;
            cin >> x;
            if(x){
                cnt ++;
                if(x != a[i]) op = 0;
            }
        }
        if(op && cnt)cout << "Da Jiang!!!" << '\n';
        else cout << "Ai Ya" << '\n';
    }
}
 
int main(){
	int t = 1;
	// cin >> t;
	while(t --)
	solve();
	return 0;
}