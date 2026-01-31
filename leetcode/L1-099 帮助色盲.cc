#include<iostream>
 
using namespace std;
 
void solve(){
	int A, B;
    cin >> A >> B;
 
    if (A == 2) { // 黄灯
        cout << "-" << endl;
        cout << "stop" << endl;
    } else if (B == 1) { // 前方两米内有人
        cout << "-" << endl;
        if (A == 1) { // 绿灯
            cout << "move" << endl;
        } else { // 红灯
            cout << "stop" << endl;
        }
    } else { // 前方两米内没有人
        if (A == 1) { // 绿灯
            cout << "dudu" << endl;
            cout << "move" << endl;
        } else { // 红灯
            cout << "biii" << endl;
            cout << "stop" << endl;
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
 