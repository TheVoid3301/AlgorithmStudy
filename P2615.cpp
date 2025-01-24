#include <iostream>
#include <vector>
using namespace std;

int main ()
{
    int n;
    cin >> n;
    vector<vector<int>> res(n, vector<int>(n, 0));
    pair<int, int> pre = {0, n / 2};
    res[0][n / 2] = 1;
    for (int i = 2; i <= n * n; ++i)
    {
        if(pre.first == 0 && pre.second != (n - 1))
        {
            res[n - 1][pre.second + 1] = i;
            pre = {n - 1, pre.second + 1};
        }
        else if (pre.second == (n - 1) && pre.first != 0)
        {
            res[pre.first - 1][0] = i;
            pre = {pre.first - 1, 0};
        }
        else if (pre.first == 0 && pre.second == (n - 1))
        {
            res[1][n - 1] = i;
            pre = {1, n - 1};
        }
        else if (pre.first != 0 && pre.second != (n - 1))
        {
            if (res[pre.first - 1][pre.second + 1] == 0)
            {
                res[pre.first - 1][pre.second + 1] = i;
                pre = {pre.first - 1, pre.second + 1};
            }
            else
            {
                res[pre.first + 1][pre.second] = i;
                pre = {pre.first + 1, pre.second};
            }
        }
    }
    for (auto i : res)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}