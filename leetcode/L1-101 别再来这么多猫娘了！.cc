#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
 
void solve(){
	int n;
    cin >> n;
    cin.ignore(); // 忽略换行符
 
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        getline(cin, s[i]);
    }
 
    int m;
    cin >> m;
    cin.ignore(); // 忽略换行符
 
    if (m == 0) {
        cout << 0 << endl << "He Xie Ni Quan Jia!";
    } else {
        int cnt = 0;
        string ss;
        getline(cin, ss);
 
        for (int i = 0; i < n; i++) {
            while(ss.find(s[i])!=-1)
            {
                int t= ss.find(s[i]);
                cnt++;
                ss.erase(t,s[i].length());
                ss.insert(t,"_");
            }
        }
 
        if (cnt >= m) {
            cout << cnt << endl << "He Xie Ni Quan Jia!";
        } else {
            while(ss.find("_")!=-1)
            {
                int t= ss.find("_");
                ss.erase(t,1);
                ss.insert(t,"<censored>");
            }
            cout << ss;
        }
    }
}
 
int main(){
	int t = 1;
	// cin >> t;
	while(t --)
	solve();
	return 0;
}
 