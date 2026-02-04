#include <bits/stdc++.h>
using namespace std;
const int MAXN = 510;
int N, M;
vector<int> graph[MAXN];
unordered_set<int> lost;
int liantong;
int pre[MAXN];
int find(int x) {
    if(x==pre[x]) return x;
    return pre[x] = find(pre[x]);
}
void join(int x, int y) {
    int fx = find(x), fy = find(y);
    if (fx!=fy) {
        pre[fx] = fy;
    }
}
bool lost_city() {
    unordered_set<int> lian;
    for (int i = 0; i<N; i++) {
        pre[i] = i;
    }
    for (int i = 0; i<N; i++) {
        if (lost.find(i)==lost.end()) {
            for (auto &v: graph[i]) {
                if (lost.find(v)==lost.end()) {
                    join(i, v);
                }
            }
        }
    }
    for (int i = 0; i<N; i++) {
        if (lost.find(i)==lost.end()) {
            int fi = find(i);
            if (lian.find(fi)==lian.end()) {
                lian.insert(fi);
            }
        }
    }
    if (liantong<lian.size()) {
        liantong = lian.size();
        return true;
    }
    liantong = lian.size();
    return false;
}
int main() {
    cin>>N>>M;
    for (int i = 0; i < M; i++) {
        int u, v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int K;
    cin>>K;
    lost_city();
    for (int i = 0; i<K; i++) {
        int city;
        cin>>city;
        lost.insert(city);
        if (lost_city()) {
            printf("Red Alert: City %d is lost!\n", city);
        }
        else {
            printf("City %d is lost.\n", city);
        }
        if (lost.size()==N) {
            printf("Game Over.\n");
        }
    }
}
