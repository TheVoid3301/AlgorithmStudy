#include<algorithm>
#include <iostream>
#include<cstring>
#include<map>
#include <cstdio>
using namespace std;
typedef long long ll;
const int maxn=1e3+10;
int n,m;
int heap[maxn];
map<int,int> pos;
void up(int x){
    while(x>1){
        if(heap[x]<heap[x/2]){
            swap(heap[x],heap[x/2]);
            x/=2;
        }
        else break;
    }
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        heap[i]=x;
        up(i);
    }
    for(int i=1;i<=n;i++) pos[heap[i]]=i;
    while(m--){
        int x;
        string s;
        cin>>x>>s;
        if(s[0]=='a'){
            int y;
            cin>>y;
            cin>>s>>s;
            if((pos[x]^1)==pos[y]) printf("T\n");
            //异或运算优先级低于==
            else printf("F\n");
        }else{
            cin>>s>>s;
            if(s[0]=='r'){
                if(pos[x]==1) printf("T\n");
                else printf("F\n");
            }else if(s[0]=='p'){
                cin>>s;
                int y;
                cin>>y;
                if(pos[y]/2==pos[x]) printf("T\n");
                else printf("F\n");
            }else{
                cin>>s;
                int y;
                cin>>y;
                if(pos[x]/2==pos[y]) printf("T\n");
                else printf("F\n");
            }
        }
    }
    return 0;
}