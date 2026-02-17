#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
using namespace std;
typedef long long ll;
const int inf=0x7fffffff;
const int N=10000+100;
int has[N],num[N];
void solve(int x)
{
    int c=x;
    for(; ;)
    {
        int tt=0;
        while(x!=0)
        {
            tt+=(x%10)*(x%10);
            x=x/10;
        }
        num[c]++;
        if(tt==1)
            break;
        if(tt==4)
        {
            has[c]=-1;
            break;
        }
        has[tt]=-1;
        x=tt;
    }
}
bool check(int x)
{
    if(x<=1)    return 0;
    for(int i=2;i*i<=x;i++)
        if(x%i==0)
            return 0;
    return 1;
}
int main()
{
    int a,b;
    int flag=0;
    scanf("%d %d",&a,&b);
    for(int i=a;i<=b;i++)
    {
        solve(i);
    }
    for(int i=a;i<=b;i++)
        if(has[i]!=-1)
         {
             flag=1;
             if(check(i)==0)
                cout<<i<<" "<<num[i]<<endl;
             else
                cout<<i<<" "<<num[i]*2<<endl;
         }
    if(flag==0)
        cout<<"SAD"<<endl;

    return 0;
}