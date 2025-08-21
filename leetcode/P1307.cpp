#include <iostream>
using namespace std;
int res = 0;
void check (int n)
{
    while (n > 0)
    {
        res = res * 10 + n % 10;
        n /= 10;
    }
}
int main ()
{
    int n;
    cin >> n;
    check(abs(n));
    cout << ((n >= 0) ? res : -res); 
    return 0;
}