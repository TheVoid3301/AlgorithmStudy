#include<stdio.h>
#include<algorithm>
using namespace std;
struct E
{
	double amount;
	double price;
	double avg;
};

bool cmp(E  a, E b)
{
	return a.avg > b.avg;
}

E buf[1111];
int main()
{
	int n=0, m=0, t=0, i=0;
	double sum;
	sum = t = 0;
	scanf("%d", &n);
	scanf("%d", &m);
	for (i = 0; i < n; i++)
	{
		scanf("%lf", &buf[i].amount);
	}
	for (i = 0; i < n; i++)
	{
		scanf("%lf", &buf[i].price);
	}
	for (i = 0; i < n; i++)
	{
		buf[i].avg = buf[i].price / buf[i].amount;
	}
	sort(buf, buf + n, cmp); //从buf[0]到buf[n] 左闭右开
	for (i = 0; i < n; i++)
	{
		if (buf[i].amount <= m)
		{
			sum += buf[i].price;
			m=m-buf[i].amount;
		}
		else
		{
			sum += buf[i].avg * m;
			break;
		}
	}
	printf("%.2lf", sum);
	return 0;

}
