#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <climits>
using namespace std;

bool checksu (int n)
{
    if(n == 0 || n == 1)
    {
        return false;
    }
    for (int i = 2; i <= (int)sqrt(n); ++i)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}
int main ()
{
    string s;
    vector<int> cou(26, 0);
    cin >> s;
    for (auto i : s)
    {
        cou[i - 'a']++;
    }
    int maxn = 0, minn = INT_MAX;
    for (auto i : cou)
    {
        if (i == 0)
        {
            continue;
        }
        if (i > maxn)
        {
            maxn = i;
        }
        if (i < minn)
        {
            minn = i;
        }
    }
    if (checksu(maxn - minn))
    {
        cout << "Lucky Word" << endl << maxn - minn;
    }
    else
    {
        cout << "No Answer" << endl << 0;
    }
    return 0;
}