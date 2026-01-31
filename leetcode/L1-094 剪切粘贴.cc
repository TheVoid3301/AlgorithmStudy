#include<iostream>
#include<cstring>
using namespace std;
 
void solve(){
    string s;
    getline(cin, s);
    int n;
    cin >> n;
    cin.ignore();
 
    while (n--) {
        int a, b;
        cin >> a >> b;
        a--, b--; // 调整为0-based索引
        string c, d;
        cin >> c >> d;
 
        string temp = s.substr(a, b - a + 1); // 剪切内容
        string check = c + d; // 检查的字符串
        s.erase(a, b - a + 1); // 删除剪切部分
 
        int pos = s.find(check); // 查找插入位置
        if (pos == -1) {
            s += temp; // 如果找不到插入位置，插入到末尾
        } else {
            s = s.substr(0, pos + c.size()) + temp + s.substr(pos + c.size()); // 插入到找到的位置
        }
    }
 
    cout << s << endl;
}
 
int main(){
	int t = 1;
	// cin >> t;
	while(t --)
	solve();
	return 0;
}