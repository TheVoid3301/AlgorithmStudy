#include <iostream>
using namespace std;
int main()
{
  // 请在此输入您的代码
  struct Record
  {
    char correct;
    char userdo;
    long long dotime;
  };
  Record r;
  int Maxhit = 0;
  int currenthit = 0;
  long long predotime = 0;
  while(cin>>r.correct>>r.userdo>>r.dotime)
  {
    if(r.correct==r.userdo)
    {
      if(r.dotime-predotime<=1000)
      currenthit++;
      else
      currenthit=1;
    }
    else 
    {
      currenthit=0;
      }
    predotime=r.dotime;
    if(Maxhit<currenthit)
    {
      Maxhit=currenthit;
    }
  }
  cout<<Maxhit;
  return 0;
}