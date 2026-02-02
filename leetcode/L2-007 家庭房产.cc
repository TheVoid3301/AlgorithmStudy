#include <bits/stdc++.h>
using namespace std;
int fa[10050]; //记录祖先
set<int> peo;  //记录所有人的编号，在输入的时候记录就行了，有的编号输入时出现不止一次所以用set确保唯一
struct people  //房产信息，完全可以用map来代替head数组
{
    int rooms;
    double S;
} head[10050];
struct answer //结果，一个家族的全部信息，用最小编号映射家族信息
{
    int minid;
    int num;
    int rooms;
    double S;
}; //家庭个数
map<int, answer> mp;
void init() //fa数组初始化
{
    for (int i = 0; i < 10050; i++)
        fa[i] = i;
}

int Find(int a) //找祖先
{
    if (fa[a] == a)
        return a;
    else
        return fa[a] = Find(fa[a]);
}

void Union(int a, int b) //合并祖先
{
    int f1 = Find(a);
    int f2 = Find(b);
    if (f1 < f2)     //最小的为祖先
        fa[f2] = f1; //修改的是祖先的祖先，祖先的祖先就是其本身
    else
        fa[f1] = f2;
}
//排序比较函数
bool cmp(answer &a1, answer &a2)
{
    if (a1.S / a1.num == a2.S / a2.num)
        return a1.minid < a2.minid;
    return a1.S / a1.num > a2.S / a2.num;
}

void test()
{
    init();
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int id, p1, p2, knum, k;//分别代表 本人 父 母 孩子数量 孩子
        cin >> id >> p1 >> p2 >> knum;
        peo.insert(id);//记录所有编号
        if (p1 != -1)
        {
            peo.insert(p1);//记录所有编号
            Union(id, p1);
        }
        if (p2 != -1)
        {
            peo.insert(p2);//记录所有编号
            Union(id, p2);
        }
        for (int j = 0; j < knum; j++)
        {
            cin >> k;
            peo.insert(k);//记录所有编号
            Union(id, k);
        }
        cin >> head[id].rooms >> head[id].S;
    }

    for (int i : peo)//遍历set，只需要得到编号即可，mp中保存的是最后结果
    {
        int id = Find(i);
        mp[id].minid = id;
        mp[id].num++;
        mp[id].S += head[i].S;
        mp[id].rooms += head[i].rooms;
    }
    cout << mp.size() << endl;
    vector<answer> res;//转到数组中对其进行排序输出
    for (auto i : mp)
    {
        res.push_back(i.second);
    }
    //排序
    sort(res.begin(), res.end(), cmp);
    //输出结果
    for (auto i : res)
        printf("%04d %d %.3lf %.3lf\n", i.minid, i.num, 1.0 * i.rooms / i.num, 1.0 * i.S / i.num);
}

int main()
{
    test();
    return 0;
}