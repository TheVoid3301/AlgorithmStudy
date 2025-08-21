#include <iostream>
#include <string>
using namespace std;
int main()
{
  // 请在此输入您的代码
  string s;
  char c;
  getline(cin, s);
  for(int i = 0; i < s.size() / 2; ++i)
  {
    c = s[i];
    s[i] = s[s.size() - i - 1];
    s[s.size() - i - 1] = c;
  }
  cout << s;
  return 0;
}