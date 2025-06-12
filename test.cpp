#include <iostream>
using namespace std;

int main() {
    cout << "Hello, World!" << endl;  // endl 会刷新缓冲区
    // 或
    cout << "Hello, World!" << flush;  // 仅刷新，不换行
    return 0;
}