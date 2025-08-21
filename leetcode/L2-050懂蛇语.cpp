#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, p;
    cin >> n;
    string s;
    getchar();
    map<string, vector<string>> m;
    for (int i = 0; i < n; ++i) {
        getline(cin, s);
        bool f = true;
        string in = "";
        for (int j = 0; j < s.size(); ++j) {
            if (s[j] == ' ') {
                f = true;
                continue;
            }
            if (f) {
                in += s[j];
                f = false;
            }
        }
        m[in].push_back(s);
    }
    cin >> p;
    getchar();
    for (int i = 0; i < p; ++i) {
        getline(cin, s);
        string res = "";
        bool f = true;
        for (int j = 0; j < s.size(); ++j) {
            if (s[j] == ' ') {
                f = true;
                continue;
            }
            if (f) {
                res += s[j];
                f = false;
            }
        }
        if (m.count(res)) {
            vector<string> vs = m[res];
            sort(vs.begin(), vs.end());
            string ot = "";
            for (int h = 0; h < vs.size(); ++h) {
                ot = ot + vs[h] + "|";
            }
            ot.erase(ot.size() - 1);
            cout << ot << endl;
        } else {
            cout << s << endl;
        }
    }
}