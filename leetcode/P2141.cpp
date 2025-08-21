#include <iostream>
using namespace std;

const int N = 105, M = 2e4 + 5;

int a[N];
bool f[M];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        f[a[i]] = true;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            if (f[a[i] + a[j]])
            {
                ans++;
                f[a[i] + a[j]] = false;
            }
    cout << ans;
    return 0;
}