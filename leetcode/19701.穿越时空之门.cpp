#include <iostream>
using namespace std;
int main()
{
  // 请在此输入您的代码
  int res = 0;
  for(int i = 1; i <= 2024; ++i)
  {
    int a = 0, b = 0, k = i;
    while (k > 0)
    {
      a += (k % 2);
      k /= 2;
    }
    k = i;
    while (k > 0)
    {
      b += (k % 4);
      k /= 4;
    }
    if(a == b)
    {
      ++res;
    }
  }
  cout << res;
  return 0;
}