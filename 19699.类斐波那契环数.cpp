#include <iostream>
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
bool isFeb(ll key)
{
  ll k = key;
  vector<int> res;
  while(k > 0)
  {
    res.push_back(k % 10);
    k /= 10;
  }
  reverse(res.begin(), res.end());
  ll size = res.size(), start = size;
  while(1)
  {
    ll p = 0;
    for(ll m = 0; m < size; ++m)
    {
      p += res[start - m - 1];
    }
    if (p < key)
    {
      ++start;
      res.push_back(p);
    }
    else if (p == key)
    {
      return true;
    }
    else if (p > key)
    {
      return false;
    }
  }
  return false;
}

int main()
{
  // 请在此输入您的代码
  for(ll i = 10000000; i >= 0; --i)
  {
    if(isFeb(i))
    {
      cout << i;
      break;
    }
  }
  return 0;
}