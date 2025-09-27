#include<bits/stdc++.h>
using namespace std;
long long n,w,a[1010],f[100010];
int main(){
	cin>>n>>w;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=10010;i++)f[i]=1145141919;
	for(int i=1;i<=n;i++)
		for(int j=a[i];j<=w;j++)
			f[j]=min(f[j],f[j-a[i]]+1);
	cout<<f[w]<<endl;
	return 0;
} 
