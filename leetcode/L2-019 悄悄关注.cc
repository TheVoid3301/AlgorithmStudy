#include <iostream>
#include <set>
#include <map>
using namespace std;
set<string>a;
map<string, int>b;
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		a.insert(s);     
	}  //得到有序的关注用户ID
	int m;
	cin >> m;
	int sum=0;  //点赞次数和
	double avg;  //平均点赞次数
	for (int i = 0; i < m; i++) {
		string s;
		int num;
		cin >> s >> num;
		sum += num;
		if (a.find(s) == a.end()) {   //点赞但是并未在关注用户名单（a）里
			 b.insert(map<string,int>::value_type(s,num));
		}
	}
	avg = (double)sum / m;
	int flag = 0;  //标记是否有悄悄关注
	map<string, int>::iterator it;
	for (it = b.begin(); it != b.end(); it++) {
		if ((double)it->second > avg) {
			cout << it->first << endl;
			flag = 1;
		}
	}
	if (flag == 0) cout << "Bing Mei You";
	return 0;
}