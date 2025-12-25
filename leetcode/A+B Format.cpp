#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    string st = to_string(a + b);
    string s = "";
    int i = st.size() - 1;
    int t = 0;
    while (i >= 0) {
        s.insert(0, 1, st[i]);
        ++t;
        if (t % 3 == 0 && t != 0) {
            s.insert(0, ",");
        }
        --i;
    }
    if (s[0] == ',') {
        s.erase(0, 1);
    } else if (s[0] == '-' && s[1] == ',') {
        s.erase(1, 1);
    }
    cout << s;
    return 0;
}