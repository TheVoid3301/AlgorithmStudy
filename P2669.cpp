#include <iostream>
using namespace std;

int main()
{
    int day = 0, n, m = 1;
    cin >> n;
    while (n - m > 0)
    {
        day++;
        n = n - m;
        ++m;
    }
    int res = 0;
    for (int i = 1; i <= day; ++i)
    {
        res += i * i;
    }
    res += n * m;
    cout << res;
    return 0;
}