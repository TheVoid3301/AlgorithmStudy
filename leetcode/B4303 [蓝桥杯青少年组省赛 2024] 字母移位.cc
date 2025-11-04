#include <iostream>

using namespace std;

typedef long long LL;

const int N = 1e5 + 10;

int n;
string str;
int a[N];
LL s[N];

char move(char c, LL d)
{
    return ((c - 'a' + d) % 26 + 26) % 26 + 'a';
}

int main()
{
    cin >> n >> str;
    str = ' ' + str;
    
    for (int i = 1; i <= n; ++ i )
    {
        cin >> a[i];
        if (i & 1)
            a[i] = -a[i];
    }

    for (int i = n; i; -- i )
        s[i] = s[i + 1] + a[i];

    for (int i = 1; i <= n; ++ i )
        cout << move(str[i], s[i]);
    
    return 0;
}
