#include<iostream>
#include<set>
using namespace std;
int main()
{
    int n;
    cin>>n;
    set<int>sc;
    for(int i=0;i<n;i++)
    {
        int k;
        scanf("%d",&k);
        set<int>::iterator it=sc.lower_bound(k);
        if(it!=sc.end())
        {
            sc.erase(it);
            sc.insert(k);
        }
        else
        sc.insert(k);
    }
    cout<<sc.size();
}