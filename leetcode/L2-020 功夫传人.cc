#include<bits/stdc++.h>
using namespace std;
int n,k,x,vis[100010];
double sum,z,r;
vector<vector<int>>v;
void dfs(int index,double power)
{
	if(vis[index])
	{
		sum+=power*v[index][0];
		return ;
	}
	for(int i=0;i<v[index].size();i++)
		dfs(v[index][i],power*(1-r/100));
}
int main()
{
	cin>>n>>z>>r;
	v.resize(n);
	for(int i=0;i<n;i++)
	{
		cin>>k;
		if(!k)
		{
			cin>>x;
			vis[i]=1;
			v[i].push_back(x);
		}
		while(k--)
		{
			cin>>x;
			v[i].push_back(x);
		}
	}
	dfs(0,z);
	cout<<(int)sum;
}
	
