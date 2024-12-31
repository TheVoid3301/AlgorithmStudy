#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
  // 请在此输入您的代码
  string a, b;
  cin >> a >> b;
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  int i = 0;
  while(i < a.size() && i < b.size())
  {
    if(a[i] != b[i])
    {
      if(a.size() < b.size())
      {
        cout << b[i];
        return 0;
      }
      else
      {
        cout << a[i];
        return 0;
      }
    }
    ++i;
  }
  if(a.size() < b.size())
  {
    cout << *(--b.end());
  }
  else
  {
    cout << *(--a.end());
  }
  return 0;
}