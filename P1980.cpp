#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n, key, count = 0;
    string s;
    cin >> n >> key;
    for(int i = 1; i <= n; ++i)
    {
        s = to_string(i);
        for(auto i : s)
        {
            if(i - '0' == key)
            {
                count++;
            }
        }
    }
    cout << count;
    return 0;
}