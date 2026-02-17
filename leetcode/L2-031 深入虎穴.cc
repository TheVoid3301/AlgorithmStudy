#include <iostream>
#include <cstdio>
#define MAX 100005
using namespace std;
int n,m,t;
int f[MAX],val[MAX];
void get(int k) {
    if(f[k] == 0) {
        val[k] = 1;
        return;
    }
    if(val[f[k]] == 0) get(f[k]);
    val[k] = val[f[k]] + 1;
}
int main() {
    int k,d;
    scanf("%d",&n);
    for(int i = 1;i <= n;i ++) {
        scanf("%d",&k);
        for(int j = 0;j < k;j ++) {
            scanf("%d",&d);
            f[d] = i;
        }
    }
    for(int i = 1;i <= n;i ++) {
        get(i);
        if(m < val[i]) m = val[i],t = i;
    }
    printf("%d",t);
    return 0;
}