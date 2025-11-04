#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    while (s[0] == '0')
    {
        s.erase(s.begin());
    }
    swap(s[0], s.back());
    while (s[0] == '0')
    {
        s.erase(s.begin());
    }
    cout << s;
    return 0;
}