#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
void GordenGhost();
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    GordenGhost();
    return 0;
}
void GordenGhost(){
    string s;
    cin>>s;
    if (s.size()==6){
        for (int i=0;i<4;i++)cout<<s[i];
        cout<<'-'<<s[4]<<s[5];
        return;
    }
    int a=(s[0]-'0')*10+s[1]-'0';
    if (a<22)a=a+2000;
    else a=a+1900;
    string b;
    b+=s[2];b+=+s[3];
    cout<<a<<'-'<<b;
}