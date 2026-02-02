#include "cstdio"
#include "algorithm"
#include "cstring"
using namespace std;
const int maxn = 10000+10;
int res[maxn], pos[maxn], in[maxn];
void build(int L, int R, int idx, int root) {
    if (L > R) return;
    res[idx] = pos[root];
    int i = L;
    while (in[i] != pos[root]) i++;
    build(L, i-1, idx*2+1, root-1-R+i);
    build(i+1, R, idx*2+2, root-1);
}
int main(int argc, char const *argv[])
{
    int N;
    scanf("%d", &N);
    for (int i = 0; i < 10000; i++) res[i] = -1;
    for (int i = 0; i < N; i++) scanf("%d", pos+i);
    for (int i = 0; i < N; i++) scanf("%d", in+i);
    build(0, N-1, 0, N-1);
    printf("%d", res[0]);
    int cnt = 1;
    int i = 1;
    while (cnt < N) {
        if (res[i] != -1) {
            printf(" %d", res[i]);
            cnt++;
        }
        i++;
    }
    printf("\n");
    return 0;
}