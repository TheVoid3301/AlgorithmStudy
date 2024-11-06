/*
 * @Author: thevoid3301
 * @Date: 2024-05-03 23:34:53
 * @Description: Maybe the test
 */
#include <bits/stdc++.h>
#define ll long long
#define mem(s, i) memset(s, i, sizeof(s))
#define pb push_back
#define pli pair<int, int>
#define INF 0x7fffffff
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9;
int n, cnt1 = 0, cnt2 = 0;
int deg[N], head[N];
string st[N];
unordered_map<string, int>mp;

struct node{
    int id;
    string s;
    friend bool operator < (node a, node b){
        return a.s > b.s;
    }
};

struct Edge{
    int to;
    int next;
}edge[N];

void add_edge(int u, int v){
    edge[cnt2].to = v;
    edge[cnt2].next = head[u];
    head[u] = cnt2++;
}

void solve(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    vector<string> pre;
    mem(head, -1);
    for(int i = 1; i <=n; ++i){
        vector<string> v;
        string s;
        cin >> s;
        int cnt = 0;
        for(int j = 0; j < s.size(); ++j){
            if(s[j] == '.'){
                string str = s.substr(j - cnt, cnt);
                if(!mp[str])    st[++cnt1] = str, mp[str] = cnt1;
                v.pb(str);
                cnt = 0;
            }else if(j == s.size() - 1){
                string str = s.substr(j - cnt, cnt + 1);
                if(!mp[str])    st[++cnt1] = str, mp[str] = cnt1;
                v.pb(str);
            }else   ++cnt;
        }
        if(i == 1)  pre = v;
        else {
			if (pre.size() == v.size()) {
				for (int i = 0; i < pre.size(); i++) {
					if (pre[i] != v[i]) {
						add_edge(mp[pre[i]], mp[v[i]]);
						deg[mp[v[i]]]++;
						break;
					} else continue;
				}
			}
			pre = v;
		}
	}
	//优先队列字典序拓扑排序 
	priority_queue<node> pq;
	for (int i = 1; i <= cnt1; i++) {
		if (deg[i] == 0) {
			pq.push({i, st[i]});
		}
	}
	vector<string> res;
	while (!pq.empty()) {
		node t = pq.top();
		res.pb(t.s);
		pq.pop();
		for (int j = head[t.id]; j != -1; j = edge[j].next) {
			deg[edge[j].to]--;
			if (deg[edge[j].to] == 0) pq.push({edge[j].to, st[edge[j].to]});
		}
		if (res.size() == cnt1) break;
	}
	for (int i = 0; i < res.size(); i++) {
		if (i != res.size() - 1)cout << res[i] << '.';
		else cout << res[i] << endl;
	}
}


int main() {
	int t = 1;
//	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
