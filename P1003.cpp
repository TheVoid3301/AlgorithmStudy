/*
 * @Author: thevoid3301
 * @Date: 2024-05-05 00:33:39
 * @Description: Maybe the test
 */
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
int a[N],b[N],g[N],k[N],n,m,t,ans=-1;
signed main(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>b[i]>>g[i]>>k[i];
	int x,y;
	cin>>x>>y;//点的坐标
	for(int i=1;i<=n;i++){
		if((x>=a[i]&&x<=a[i]+g[i])&&(y>=b[i]&&y<=b[i]+k[i]))//判断是否覆盖点位
			ans=i;//更新答案
	}
	cout<<ans;
	return 0;
}