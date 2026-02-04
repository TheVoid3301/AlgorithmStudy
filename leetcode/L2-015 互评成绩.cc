#include<bits/stdc++.h>
using namespace std;
bool cmp(double a,double b){
	return a>b;
}
int main(){
	int n,k,m,num;
	cin>>n>>k>>m;
	double b[n];//记录每个人的平均分
	for(int i=0;i<n;i++){
		double max=-1;
		double min=101;
		double avg,sum=0;
		for(int j=0;j<k;j++){
			cin>>num;
			sum+=num;
			if(num>max)
			max=num;//记录最大值
			if(num<min)
			min=num;//记录最小值
		}
		sum=sum-min-max;
		avg=sum/(k-2);//得到平均值
		b[i]=avg;
	}
	sort(b,b+n,cmp);//从大到小排序
	for(int i=m-1;i>=0;i--){
		if(i>0)
		printf("%.3lf ",b[i]);
		else
		printf("%.3lf",b[i]);
	}
}