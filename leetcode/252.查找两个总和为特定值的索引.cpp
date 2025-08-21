#include <iostream>
#include <vector>
using namespace std;
int main()
{
  // 请在此输入您的代码
  vector<int> v;
  int n, k, a, b;
  cin >> n;
  for(int i = 0; i < n; ++i)
  {
    cin >> k;
    v.push_back(k);
  }
  cin >> k;
  for(int i = 0; i < n; ++i)
  {
    for(int j = i + 1; j < n; ++j)
    {
      if(v[i] + v[j] == k)
      {
        cout << i << " " << j;
        return 0;
      }
    }
  }
  return 0;
}