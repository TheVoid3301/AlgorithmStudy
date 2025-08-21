#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    int res = 0, count = 1;
    cin >> s;
    for (int i = 0; i < s.size() - 1; ++i) {
        if (s[i] >= '0' && s[i] <= '9') {
            res += (s[i] - '0') * count;
            ++count;
        }
    }
    if (res % 11 == s[s.size() - 1] - '0' || res % 11 == 10 && s[s.size() - 1] == 'X') {
        cout << "Right";
    } else if (res % 11 == 10) {
        s[s.size() - 1] = 'X';
        cout << s;
    } else {
        s[s.size() - 1] = '0' + res % 11;
        cout << s;
    }
    return 0;
}