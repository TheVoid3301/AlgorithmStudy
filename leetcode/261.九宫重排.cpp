#include<iostream>
#include<queue>
#include<map>
using namespace std;
string s1, s2;
map<string, int> mp;
int dir[4][2] = { -1,0,0,1,1,0,0,-1 };
void bfs()
{
    queue<string> q;
    q.push(s1);
    mp[s1] = 0;
    while (!q.empty())
    {
        string p = q.front();
        q.pop();
        int dist = mp[p];
        if (p == s2)
        {
            cout << mp[s2];
            return;
        }
        int k = p.find('.');
        int x = k / 3, y = k % 3;
        int tx, ty;
        for (int i = 0; i < 4; i++)
        {
            tx = x + dir[i][0];
            ty = y + dir[i][1];
            if (tx < 0 || tx>2 || ty < 0 || ty>2)continue;
            int tk = tx * 3 + ty;
            swap(p[k], p[tk]);
            if (mp.count(p) == 0)
            {
                mp[p] = dist + 1;
                q.push(p);
            }
            swap(p[k], p[tk]);
        }
    }
}
int main()
{
    cin >> s1 >> s2;
    bfs();
}