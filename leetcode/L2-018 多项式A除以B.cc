#include "cstring"
#include "cstdio"
using namespace std;
double bige[10000]; // 较大的多项式（被除的多项式）
double smalle[10000]; // 较小的多项式
double ans[10000];
int bigbige;
int smallbige;
bool iszero(double val){ 
//根据题给条件来判断是不是0
//因为printf自带四舍五入 所以就用这种方式...
	char str[50];
	sprintf(str, "%.1f", val);
	double vall;
	sscanf(str, "%lf", &vall);
	return vall == 0.0;
}
int main(){
	for(int i = 0; i < 10000; ++i)
		smalle[i] = bige[i] = ans[i] = 0.0;
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n ; ++i){
		int a;
		double b;
		scanf("%d %lf", &a, &b);
		bige[a] = b; 
		if(i == 0) bigbige = a;
	}
	scanf("%d", &n);
	for(int i = 0; i < n ; ++i){
		int a;
		double b;
		scanf("%d %lf", &a, &b);
		smalle[a] = b;
		if(i == 0) smallbige = a;
	}
	//smallbige , bigbige分别指较小的多项式和较大多项式的最大非零指数
	//模拟
	for(int p1 = bigbige; p1 >= smallbige; p1--){
		if(bige[p1] != 0.0){
			ans[p1 - smallbige] = bige[p1] / smalle[smallbige];
			for(int p2 = smallbige; p2 >= 0; p2--)
				if(smalle[p2] != 0.0)
					bige[p1 - smallbige + p2] -= ans[p1 - smallbige] * smalle[p2];
		}
	}
	int anscnt = 0;
	int yucnt = 0;
	//统计
	for(int i = bigbige - smallbige; i >= 0; --i)
		if(!iszero(ans[i])) anscnt++;
	for(int i = smallbige; i >= 0; --i)
		if(!iszero(bige[i])) yucnt++;
	//输出
	if(anscnt == 0) printf("0 0 0.0\n");
	else{
		printf("%d", anscnt);
		for(int i = bigbige - smallbige; i >= 0; --i)
			if(!iszero(ans[i])) printf(" %d %.1f", i, ans[i]);
		printf("\n");
	}
	if(yucnt == 0) printf("0 0 0.0\n");
	else{
		printf("%d", yucnt);
		for(int i = smallbige; i >= 0; --i)
			if(!iszero(bige[i])) printf(" %d %.1f", i, bige[i]);
		printf("\n");
	}
}
