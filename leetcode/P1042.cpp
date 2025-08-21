#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    char a;
    string s;
    int l11 = 0, r11 = 0, l21 = 0, r21 = 0;;
    vector<pair<int, int>> res11, res21;
    while (1) {
        cin >> a;
        if (a == 'W') {
            l11++;
            l21++;
        } else if (a == 'L') {
            r11++;
            r21++;
        }
        if ((l11 >= 11 || r11 >= 11) && abs(l11 - r11) >= 2) {
            res11.push_back({l11, r11});
            l11 = 0;
            r11 = 0;
        }
        if ((r21 >= 21 || l21 >= 21) && abs(l21 - r21) >= 2) {
            res21.push_back({l21, r21});
            r21 = 0;
            l21 = 0;
        }
        if (a == 'E') {
            res11.push_back({l11, r11});
            res21.push_back({l21, r21});
            break;
        }
    }
    for (auto i : res11) {
        cout << i.first << ':' << i.second << endl;
    }
    cout << endl;
    for (auto i : res21) {
        cout << i.first << ':' << i.second << endl;
    }
    return 0;
}