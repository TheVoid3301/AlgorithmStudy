#include <iostream>
#include <vector>
using namespace std;

int main ()
{
    int n;
    cin >> n;
    vector<int> num(n , 0);
    for (int i = 0; i < n; ++i)
    {
        cin >> num[i];
    }
    return 0;
}