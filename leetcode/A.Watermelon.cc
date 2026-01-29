#include <iostream>

using namespace std;

int main() {
    int a;
    cin >> a;
    cout << ((a > 2 && a % 2 == 0) ? "YES" : "NO") << endl;
    return 0;
}