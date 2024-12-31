#include <bits/stdc++.h>
using namespace std;
int main()
{
  // 请在此输入您的代码
  string s, res;
  cin >> s;
  res.push_back(s[0]);
  int t = 1;
  for(int i = 1; i < s.size(); ++i)
  {
    if(s[i] == s[i - 1])
    {
      ++t;
    }
    else
    {
      res += to_string(t);
      res.push_back(s[i]);
      t = 1;
    }
  }
  res += to_string(t);
  if(res.size() < s.size())
  {
    cout << res;
  }
  else
  {
    cout << "NO";
  }
  return 0;
}