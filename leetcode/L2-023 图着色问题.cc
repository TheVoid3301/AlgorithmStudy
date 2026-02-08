#include <bits/stdc++.h>
using namespace std;

int main()
{
    int V,E,K;  //顶点数V,边数E,颜色数K
    cin >> V >> E >> K;
    bool Edge[V+1][V+1];
    memset(Edge,false,sizeof(Edge));  //初始化道路信息
    for(int i = 0; i < E; i++)
    {
        int x,y;
        cin >> x >> y;
        Edge[x][y] = Edge[y][x] = true;  //相邻的为true
    }
    int N;
    cin >> N;
    while(N--)
    {
        bool isLegal = true;  //判断颜色分配方案是否合法
        int a[V];
        set<int> s;
        for(int i = 1; i <= V; i++)
        {
            cin >> a[i];
            if(s.count(a[i]) != 0)
            {
                for(int j = 1; j < i; j++)
                {
                    if(a[i] == a[j] && Edge[i][j])   //若存在顶点j和顶点i颜色相同,且顶点i、j是相邻顶点
                    {
                        isLegal = false;
                    }
                }
            }
            s.insert(a[i]);
        }
        if(s.size() != K)   //这里有个测试点,必须要写不等于,我之前写的大于,只有23分
        {
            isLegal = false;
        }
        if(isLegal)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    return 0;
}