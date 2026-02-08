#include<bits/stdc++.h>
using namespace std;

const int N = 101;
struct Per{
	string name;
	int cnt = 0;
	int scnt = 0;
	double pj = -1;
	bool operator <(const Per& b)const{
		if(cnt!=b.cnt) return cnt<b.cnt;
		else return pj<b.pj;
	}
}per[N];

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n; cin >> n;
    for(int i=0; i<n; i++)
    {
    	unordered_map<int,int>mp;
    	cin >> per[i].name;
        cin >> per[i].scnt;
		for(int j=0; j<per[i].scnt; j++)
		{
			int x; cin >> x;
			if(mp.find(x)==mp.end()){
				mp.insert({x,1});
				per[i].cnt ++;
			} 
		}
		per[i].pj = 1.0*per[i].cnt/per[i].scnt;
	}
	sort(per,per+n);
	int t = 1;
	for(int i=n-1;i>=n-2;i--)	{
	  if(i>=0) cout<<per[i].name<<" ";
	  else cout<<"- ";
    }
    if(n-3>=0) cout<<per[n-3].name;
    else cout<<"-";
    
    return 0;
}
