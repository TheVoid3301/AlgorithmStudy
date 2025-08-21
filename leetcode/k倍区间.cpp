#include <iostream>
#include <vector>
using namespace std;
int main()
{
  // 请在此输入您的代码
  int n, k;
  cin >> n >> k;
  vector<int> g(n, 0);
  for (int i = 0; i < n; ++i) {
      cin >> g[i];
  }
  vector<long long> sumg(n, 0);
  sumg[0] = g[0];
  for (int i = 1; i < n; ++i) {
      sumg[i] = g[i] + sumg[i - 1];
  }
  long long res = 0;
  vector<int> yushu(k, 0);
  yushu[0] = 1;
  for (int i = 0; i < n; ++i) {
      res += yushu[sumg[i] % k];
      yushu[sumg[i] % k]++;
  }
  cout << res;
  return 0;
}