#include <bits/stdc++.h>
using namespace std;
int main(int argc, char *argv[])
{
    int cases;
    cin >> cases;
    for (int cs = 1; cs <= cases; cs++)
    {
        int n, k, d, y, b, w, nim = 0;
        cin >> n >> k >> d;
        for (int i = 0; i < n; i++)
        {
            cin >> y >> b >> w;
            nim ^= abs(b - w) - 1;
        }
        cout << (nim ? "Yes" : "No") << '\n';
    }
    return 0;
}