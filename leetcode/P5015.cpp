#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    getline(cin, s);
    int res = 0;
    for (auto i : s) {
        if (i >= 'a' && i <= 'z' || i >= 'A' && i <= 'Z'
        || i >= '0' && i <= '9') {
            ++res;
        }
    }
    cout << res;
    return 0;
}