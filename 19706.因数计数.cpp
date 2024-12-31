#include <iostream>
using namespace std;

long long a[100005], b[100005], c[100005];

int main() {
  int n, x, ub = 0;
  cin>>n;
  for (int i=1; i<=n; i++)
    cin>>x, a[x]++, ub = max(ub, x);
  // 预处理每个数的因数和倍数个数(不包括自身) 调和级数 O(nlogn)
  for (int i=1; i<=ub; i++)
    for (int j=i+i; j<=ub; j+=i)
      b[j] += a[i], c[i] += a[j];
  long long ans1 = 0, ans2 = 0;
  for (int i=1; i<=ub; i++) {
    if (a[i] == 0)
      continue;
    for (int j=i+i; j<=ub; j+=i) {
      // basic AB
      ans1 += a[i]*a[j];
      // AAB/ABB (A1,A2)(A2,B) (A1,B)(A2,B) C(2,1)C(2,1)A(2,2) + 2 = 10
      ans2 += (a[i]*a[j]*(a[j]-1)/2 + a[i]*a[j]*(a[i]-1)/2)*10;
      // ABC (A,B)(B,C) C(2,1) = 2
      ans2 += a[j]*a[i]*b[i]*2;
      // for ABC (A,C)(B,C)
      ans2 -= a[i]*a[i]*a[j];
      // ABC (A,B)(A,C) choose one multiple of j, except i
      ans2 += (c[i]-a[j])*a[i]*a[j];
    }
    // basic AB, two same
    ans1 += a[i]*(a[i]-1);
    // ABC (A,C)(B,C) choose any two of factors of i, except two same
    ans2 += b[i]*b[i]*a[i];
    // AA (A1,A2)(A2,A1)
    ans2 += a[i]*(a[i]-1);
    // AAA (A1,A2)(A1,A3) C(3,1)C(2,1)A(2,2)A(2,2) = 24
    ans2 += a[i]*(a[i]-1)*(a[i]-2)/6*24;
  }
  // cout<<ans1<<' '<<ans2<<'\n';
  cout<<ans1*ans1-ans1-ans2<<'\n';

  return 0;
}