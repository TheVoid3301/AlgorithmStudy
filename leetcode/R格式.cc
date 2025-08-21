#include<bits/stdc++.h>
using namespace std;   
int main()
{
  int n;
  string d;    //数太大用字符数组读
  cin>>n>>d;
  vector<int>b;  //开vetor好处就是可以用push_back进位的时候可以在后面直接加
  int sum=0,k=0;
  for(int i=d.size()-1;i>=0;i--)
  {
      if(d[i]!='.')
      b.push_back(d[i]-'0');   //把字符型变成整数型 
      else {k=sum;}    
      sum++;   //找到小数点位置为以后输出做铺垫，现在就可以看作一个大整数了
  }
  int u=b.size();
  while(n--)   //指数类型太大，保存不了，故每次*2 
  {    
    int t=0;
      for(int i=0;i<b.size();i++)
      {
          b[i]=b[i]*2+t;   //t是进位的数
          if(b[i]>=10)
          {
              t=b[i]/10;
              b[i]=b[i]%10;
          }
      else t=0;
      }
      if(t)
        b.push_back(t);
  }   //模拟数学过程 
  u=b.size();
  int t=1;
  if(k&&b[k-1]>=5){     // 四舍五入过程
    for(int i=k;i<u;i++)
       {
      b[i]=b[i]+1;
        if(b[i]<=9){t=0;break;}
        else b[i]-=10;
      } 
    if(t) b.push_back(t);
  }
    for(int i=b.size()-1;i>=k;i--)
      cout<<b[i];
  return 0;
}