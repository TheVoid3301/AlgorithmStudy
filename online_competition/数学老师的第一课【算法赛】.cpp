#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    int n = 0;
    getline(cin, s);
    //统计中文字符个数
    for (size_t i = 0; i < s.length(); ) {
        unsigned char c = s[i];
        if ((c & 0xE0) == 0xC0) {       // 2字节字符
            i += 2;
        } else if ((c & 0xF0) == 0xE0) { // 3字节字符（中文字符通常在此范围）
            n++;
            i += 3;
        } else if ((c & 0xF8) == 0xF0) { // 4字节字符
            i += 4;
        } else {                         // 1字节字符（ASCII）
            i += 1;
        }
    }
    cout << n;
    return 0;
}