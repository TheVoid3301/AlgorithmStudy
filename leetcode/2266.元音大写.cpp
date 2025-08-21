#include <iostream>
using namespace std;
int main()
{
  // 请在此输入您的代码
  string c = "aeiou";
  string s;
  cin >> s;
  for(int i = 0; i < s.size(); ++i)
  {
    if(c.find(s[i]) != -1)
    {
      s[i] = s[i] - 32;
    }
  }
  cout << s;
  return 0;
}