#include <iostream>
#include <vector>
using namespace std;

int main ()
{
    int n;
    cin >> n;
    vector<vector<int>> res(n, vector<int>(n, 0));
    pair<int, int> pre(0, n / 2);
    for (int i = 2; i <= n * n; ++i)
    {
        if(pre.first == 0 && pre.second != (n - 1))
        {
            res[n - 1][pre.second + 1] = i;
            pre = {n - 1, pre.second + 1};
        }
        else if (pre.second == (n - 1) && pre.first != 0)
        {
            
        }
    }
    return 0;
}