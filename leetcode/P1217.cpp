#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
vector<int> wei(10, 0);
int len = 0;
bool check (int i)
{
    while(i > 0)
    {
        wei[len] = i % 10;
        i /= 10;
        ++len;
    }
    if(len % 2 == 0)
    {
        return false;
    }
    for(int j = 0; j < len / 2; ++j)
    {
        if(wei[j] != wei[len - j - 1])
        {
            return false;
        }
    }
    return true;
}
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
int main ()
{
    int a, b;
    cin >> a >> b;
    for (int i = a; i <= b; ++i)
    {
        if (i % 2 == 0)
        {
            continue;
        }
        if(i == 11)
        {
            cout << 11 << endl;
        }
        len = 0;
        if (check(i))
        {
            if (checksu(i))
            {
                cout << i << endl;
            }
        }
    }
    return 0;
}