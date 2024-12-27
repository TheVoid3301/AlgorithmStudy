#include <iostream>
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
typedef struct peo
{
  ll cost;
  ll cishu;
}Peo;

bool cmp(Peo &a, Peo &b)
{
  return a.cishu > b.cishu;
}

int main()
{
  // 请在此输入您的代码
  ll si[100005] = {};
  ll n, s;
  cin >> n >> s;
  Peo people[100005];
  for(ll i = 1; i <= n; ++i)
  {
    cin >> people[i].cost >> people[i].cishu;
  }
  // 将士兵按需要训练的次数降序
  sort(people + 1, people + 1 + n, cmp);
  // si数组用于保存包含i个士兵时训练需要的花费
  for (int i = 1; i <= n; i++)
  {
    si[i] = si[i-1] + people[i].cost;
  }
  ll i = n, cnt = 0, res = 0;
  while(si[i] >= s)
  {
    cnt = max(cnt, people[i].cishu);
    --i;
  }
  res = cnt * s;
  while(i >= 1)
  {
    res += (people[i].cishu - cnt) * people[i].cost;
    --i;
  }
  cout << res;
  return 0;
}



// #include <iostream>
// #include <bits/stdc++.h>
// typedef long long ll;
// using namespace std;
// typedef struct peo
// {
//   ll cost;
//   ll cishu;
// }Peo;

// bool cmp(Peo &a, Peo &b)
// {
//   return a.cishu > b.cishu;
// }

// int main()
// {
//   // 请在此输入您的代码
//   ll si[100005] = {};
//   ll n, s;
//   cin >> n >> s;
//   Peo people[100005];
//   for(ll i = 1; i <= n; ++i)
//   {
//     cin >> people[i].cost >> people[i].cishu;
//   }
//   // 将士兵按需要训练的次数降序
//   sort(people + 1, people + 1 + n, cmp);
//   // si数组用于保存包含i个士兵时训练需要的花费
//   for (int i = 1; i <= n; i++)
//   {
//     si[i] = si[i-1] + people[i].cost;
//   }
//   ll i = n, cnt = 0, res = 0;
//   while(si[i - 1] >= s)
//   {
//     --i;
//   }
//   cnt = people[i].cishu;
//   res = people[i].cishu * s;
//   while(i >= 1)
//   {
//     res += (people[i].cishu - cnt) * people[i].cost;
//     --i;
//   }
//   cout << res;
//   return 0;
// }