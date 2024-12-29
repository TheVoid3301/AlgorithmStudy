// 方法一
// #include <iostream>
// #include <bits/stdc++.h>
// typedef long long ll;
// using namespace std;
// ll k, n, t;
// bool f = false;
// vector<int> grade, oi, mark(1000000, 0);

// double variance(vector<int> g)
// {
//   double ave = 0.0, res = 0.0;
//   for(auto i : g)
//   {
//     ave += i;
//   }
//   ave /= g.size();
//   for(auto i : g)
//   {
//     res += (i - ave) * (i - ave);
//   }
//   return res / g.size();
// }

// void dfs()
// {
//   if (oi.size() == k)
//   {
//     double d = variance(oi);
//     if(d < t)
//     {
//       f = true;
//       return ;
//     }
//   }
//   for(ll i = 0; i < grade.size(); ++i)
//   {
//     if(mark[i] != 1)
//     {
//       oi.push_back(grade[i]);
//       mark[i] = 1;
//       dfs();
//       oi.pop_back();
//       mark[i] = 0;
//     }
//   }
//   return ;
// }

// int main()
// {
//   // 请在此输入您的代码
//   ll g;
//   cin >> n >> k >> t;
//   for(ll i = 0; i < n; ++i)
//   {
//     cin >> g;
//     grade.push_back(g);
//     if(grade.size() >= k)
//     {
//       dfs();
//       if(f)
//       {
//         cout << grade.size();
//         return 0;
//       }
//     }
//   }
//   if(!f)
//   {
//     cout << -1;
//   }
//   return 0;
// }
// 方差是描述数据波动的数学量
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int k,t;
long long a[100005], b[100005], s[100005], sq[100005];

inline double pow(double x) { return x*x; }

bool check(int m) {
  memcpy(b, a, sizeof(long long)*(m+1));
  sort(b+1, b+1+m);
  for (int i=1; i<=m; i++)
    s[i] = s[i-1]+b[i], sq[i] = sq[i-1]+b[i]*b[i];
  for (int i=k; i<=m; i++)
    if (double(sq[i]-sq[i-k])/k - pow(double(s[i]-s[i-k])/k) < t)
      return true;
  return false;
}

int get(int l, int r) {
  int ans = -1;
  while (l <= r) {
    int m = (l+r)/2;
    if (check(m))
      r = (ans=m)-1;
    else
      l = m+1;
  }
  return ans;
}

int main() {
  int n;
  cin>>n>>k>>t;
  for (int i=1; i<=n; i++)
    cin>>a[i];
  cout<<get(k, n)<<'\n';

  return 0;
}