#include<bits/stdc++.h>
using namespace std;

const int N = 1e4 + 10;
set<int> h[N]; // 维护每个集合中元素

int main()
{
    int n; cin >> n;
    for(int i = 1; i <= n; i ++) 
    {
        int m; cin >> m;
        for(int j = 1; j <= m; j ++) 
        {
            int x; cin >> x;
            h[i].insert(x);
        }
    }
    int q; cin >> q;
    while(q --)
    {
        int a, b;
        cin >> a >> b;
        int cnt = 0; //共有元素数量
        for(auto x : h[b])
            if(h[a].count(x)) cnt ++;
        //计算答案
        int sum = h[a].size() + h[b].size();
        double res = cnt * 1.0 / (sum - cnt);
        res *= 100;
        printf("%.2lf%\n", res);
    }
    return 0;
}