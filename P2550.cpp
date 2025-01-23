#include <iostream>
#include <vector>
using namespace std;

int main ()
{
    int n, t;
    vector<bool> lotto(34, false);
    vector<int> win(7, 0);
    cin >> n;
    for (int i = 0 ; i < 7; ++i)
    {
        cin >> t;
        lotto[t] = true;
    }
    for (int i = 0; i < n; ++i)
    {
        int k = 0;
        for (int j = 0; j < 7; ++j)
        {
            cin >> t;
            if (lotto[t])
            {
                ++k;
            }
        }
        ++win[7 - k];
    }
    for (int i = 0; i <= 6; ++i)
    {
        cout << win[i] << " ";
    }
    return 0;
}