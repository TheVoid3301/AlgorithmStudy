#include<iostream>
#include<memory.h>
using namespace std;
int mother[100000];
int father[100000];
typedef struct
{
    char sex;
    int fa;
    int ma;
}Man;
Man man[100010];

int find(int a,int b,int num)
{
    if(a == -1 || b == -1)
        return 1;
    if((mother[a] != -1 && mother[a] == mother[b]) || (father[a] != -1 && father[a] == father[b]))
        return 0;
    num++;
    if(num >= 4)
        return 1;
    return (find(mother[a],mother[b],num) && find(father[a],father[b],num) && find(mother[a],father[b],num) && find(father[a],mother[b],num));
}

int main()
{
    memset(mother,-1,sizeof(mother));
    memset(father,-1,sizeof(father));
    int n;
    cin>>n;

    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        cin>>man[a].sex>>man[a].fa>>man[a].ma;
        if(man[a].fa != -1)
        {
            father[a] = man[a].fa;
            man[man[a].fa].sex = 'M';
            ///父母性别不是输入，手动确定，因为父母也可能作为测试对象
        }
        if(man[a].ma != -1)
        {
            mother[a] = man[a].ma;
            man[man[a].ma].sex = 'F';
        }

        if(man[a].fa == -1)
            father[a] = -1;
        if(man[a].ma == -1)
            mother[a] = -1;
    }

    int m;
    cin>>m;

    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;

        if(man[a].sex == man[b].sex)
            cout<<"Never Mind"<<endl;
        else
        {
            int numdai=0;
            if(find(a,b,numdai))
                cout<<"Yes"<<endl;
            else
                cout<<"No"<<endl;
        }
    }
    return 0;
}