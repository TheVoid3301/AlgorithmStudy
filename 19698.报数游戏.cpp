#include <iostream>
typedef long long ll;
using namespace std;

int main() 
{
  ll n = 202420242024;
  ll a = n / 10, b = n % 10;
  ll c[10] = {20, 24, 40, 48, 60, 72, 80, 96, 100, 120};
  cout << 120 * a + c[b - 1];
  return 0;
}