#include <iostream>
#include <string>
using namespace std;

int main() {
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    for (auto &i : s1) {
        i = tolower(i);
    }
    for (auto &i : s2) {
        i = tolower(i);
    }
    s2 += ' ';
    int len = 0, count = 0, start = 0;
    bool f = true;
    for (int i = 0; i < s2.size(); ++i) {
        if (s2[i] != ' ') {
            len++;
        } else {
            string s3 = s2.substr(i - len, len);
            if (s3 == s1) {
                if (f) {
                    f = !f;
                    start = i - len;
                }
                count++;
            }
            len = 0;
        }
    }
    if (!f) {
        cout << count << " " << start;
    } else {
        cout << -1;
    }
    return 0;
}