// 题目描述
// 实现一个算法来识别一个字符串 
// str2 是否是另一个字符串 
// str1 的排列。排列的解释如下：如果将 
// str1 的字符拆分开，重新排列后再拼接起来，能够得到 
// str2 ，那么就说字符串 str2 是字符串 str1 的排列。（不忽略大小写）
// 如果 
// str2 字符串是 
// str1 字符串的排列，则输出 YES；如果
// str2 字符串不是 str1
// str1 字符串的排列，则输出 NO；
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
  string s1, s2;
  getline(cin, s1);
  getline(cin, s2);
  int n = s1.size(), m = s2.size();
  if(n == m)
  {
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    if(s1 == s2)
      printf("YES");
    else
      printf("NO");
  }
  else
    printf("NO");
  return 0;
}