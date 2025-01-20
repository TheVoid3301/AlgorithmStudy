#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int main()
{
    int count, a[3], b[3];
    cin >> count;
    for(int i = 0; i < 3; ++i)
    {
        cin >> a[i] >> b[i];
    }
    int res = INT_MAX;
    for(int i = 0; i < 3; ++i)
    {
        res = min(res, (count % a[i]) == 0 ? (count / a[i]) * b[i] : (count / a[i] + 1) * b[i]);
    }
    cout << res;
    return 0;
}