#include <iostream>
#include <math.h>
using namespace std;
bool checksu (int k)
{
    for(int i = 2; i <= sqrt(k); ++i)
    {
        if (k % i == 0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int n, k = 2;
    cin >> n;
    while (1)
    {
        while (n % k != 0)
        {
            ++k;
            while (!checksu(k))
            {
                ++k;
            }
        }
        cout << n / k;
        break;
    }
    return 0;
}