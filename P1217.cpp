#include <iostream>
#include <string>
#include <math.h>
using namespace std;

bool check (string s)
{
    for (int i = 0; i < s.size() / 2; ++i)
    {
        if (s[i] != s[s.size() - 1 - i])
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
    string s;
    cin >> a >> b;
    for (int i = a; i <= b; ++i)
    {
        if (i % 2 == 0)
        {
            continue;
        }
        s = to_string(i);
        if (check(s))
        {
            if (checksu(i))
            {
                cout << s << endl;
            }
        }
    }
    return 0;
}