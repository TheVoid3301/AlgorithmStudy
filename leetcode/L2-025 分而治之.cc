#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N,M;   //敌方城市个数N,通路条数M
    cin >> N >> M;
    vector<int> v[N+1];
    for(int i = 0; i < M; i++)
    {
        int x,y;
        cin >> x >> y;
        v[x].push_back(y);   //表示x和y是相邻城市 
    }
    int K;   //K个方案
    cin >> K;
    while(K--)
    {
        bool isLonely = true;   //判断是不是所有的城市都被孤立了
        int Np;   //某方案计划攻下的城市数量Np
        cin >> Np;
        set<int> s;  //用来记录被攻下的城市
        for(int i = 0; i < Np; i++)
        {
            int temp;
            cin >> temp;
            s.insert(temp);
        }
        for(int i = 1; i <= N; i++)
        {
            if(s.find(i) == s.end())  //若还有没被攻陷的城市
            {
                for(int j = 0; j < v[i].size(); j++)
                {
                    if(s.find(v[i][j]) == s.end())  //若这个没被攻陷的城市还有相邻的未被攻陷的城市
                    {
                        isLonely=false;
                    }
                }
            }
        }
        if(isLonely)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}