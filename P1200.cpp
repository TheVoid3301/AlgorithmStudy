#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    int a = 1, b = 1;
    cin >> s;
    for (auto i : s) {
        a *= (i - 'A' + 1) % 47;
    }
    cin >> s;
    for (auto i : s) {
        b *= (i - 'A' + 1) % 47;
    }
    if (a % 47 == b % 47) {
        cout << "GO";
    } else {
        cout << "STAY";
    }
    return 0;
}