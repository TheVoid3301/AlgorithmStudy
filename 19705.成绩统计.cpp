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