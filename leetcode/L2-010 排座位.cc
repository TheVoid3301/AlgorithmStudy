#include <iostream>
using namespace std;
int F[105];
int Mp[105][105];
int get_far(int x){
    return F[x] == x ? x : F[x] = get_far(F[x]);
}
void Union(int x,int y){
    int a = get_far(F[x]),b = get_far(F[y]);
    if(a != b)
        F[a] = b;
}
 
int main()
{
    int n,m,k;
    while(cin>>n>>m>>k){
        for(int i = 0;i <= n;i ++)  F[i] = i;
        int x,y,v;
        for(int i = 1;i <= m;i ++){
            cin>>x>>y>>v;
            Mp[x][y] = Mp[y][x] = v;
            if(v == 1)
                Union(F[x],F[y]);
        }
        int judge1,judge2;
        for(int i = 1;i <= k;i ++){
            cin>>judge1>>judge2;
            if(Mp[judge1][judge2] == 1)  cout<<"No problem"<<endl;
            else if(Mp[judge1][judge2] == -1){
                if(get_far(F[judge1]) == get_far(F[judge2]))    cout<<"OK but..."<<endl;
                else
                    cout<<"No way"<<endl;
            }
            else
                cout<<"OK"<<endl;
        }
    }
    return 0;
}