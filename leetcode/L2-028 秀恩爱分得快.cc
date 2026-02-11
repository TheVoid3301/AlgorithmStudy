#include<bits/stdc++.h> //万能头文件
using namespace std;
int n, m;
bool sex[1005]; //存性别，false为男性
double qa[1005], qb[1005]; //存亲密度
vector<int> p[1005]; //预存照片
void the1(int t){ //处理照片
    string s;getline(cin,s);
    string v="";
    int i; for(i=0;i<(int)s.size();i++) if(s[i]==' ') break;i++; //因为用的vector存照片的人所以k没有用了
    for(;i<(int)s.size();i++){ //获取照片人的性别以及编号，注意临界条件
        if(s[i]!=' ') {
            v+=s[i];
            if(i+1==(int)s.size()){
                bool flag=false; if(v[0]=='-') flag=true,v.erase(0,1);
                int a=0; for(auto k:v) a=a*10+k-'0';
                sex[a] = flag;
                p[t].push_back(a); //a为照片人编号，并将其存入照片
            }
        }
        else if(s[i]==' '){
            bool flag=false; if(v[0]=='-') flag=true,v.erase(0,1);
            int a=0; for(auto k:v) a=a*10+k-'0';
            sex[a] = flag;
            p[t].push_back(a);
            v="";
        }
    }
}
void the2(int &a, int &b){ //处理A，B，获取编号以及性别
    string s1, s2;cin>>s1>>s2;
    bool flag=false;if(s1[0]=='-') flag=true,s1.erase(0,1);
    a=0; for(auto i:s1) a = a*10+i-'0'; sex[a]=flag;
    flag = false; if(s2[0]=='-') flag=true,s2.erase(0,1);
    b=0; for(auto i:s2) b = b*10+i-'0'; sex[b]=flag;
}
void the3(int a, int b){//计算亲密度
    for(int k=0;k<m;k++){
        int flag=0, ct=0;//我们只算A，B的亲密度
        for(auto i:p[k]) if(i==a) {flag=1;ct++;} else if(i==b) {flag=2; ct++;}
        if(ct==2){  //我总是怀疑这里有点问题，但是ac了可能是数据的原因吧
            for(auto i:p[k]) if(sex[i]!=sex[a]) qa[i]+=1.0/p[k].size();
            for(auto i:p[k]) if(sex[i]!=sex[b]) qb[i]+=1.0/p[k].size();
        }
        else if(flag==1) {for(auto i:p[k]) if(sex[i]!=sex[a]) qa[i]+=1.0/p[k].size();}
        else if(flag==2) {for(auto i:p[k]) if(sex[i]!=sex[b]) qb[i]+=1.0/p[k].size();}
    }
}
void Print(int a, int b){ //做一个打印函数，节省代码量，易于维护
    if(sex[a]) cout<<"-";
    cout<<a<<" ";
    if(sex[b]) cout<<"-";
    cout<<b<<endl;
}
int main(){
    cin>>n>>m;getchar();
    for(int i=0;i<m;i++) the1(i); //处理每一张照片
    int a,b;the2(a, b); //处理A，B
    the3(a,b); //计算亲密度
    double ma=-1,mb=-1;
    for(int i=0;i<n;i++){
            if(sex[i]!=sex[a]) ma = max(ma,qa[i]);
            if(sex[i]!=sex[b]) mb = max(mb,qb[i]);
        } //找最大亲密度
    if(ma==mb&&ma==qb[a]&&mb==qa[b]) {Print(a, b); return 0;} //如果是彼此那么直接打印，并return，如果不是的话就都打印
    for(int i=0;i<n;i++) if(ma==qa[i]&&sex[i]!=sex[a]) Print(a, i);
    for(int i=0;i<n;i++) if(mb==qb[i]&&sex[i]!=sex[b]) Print(b, i);
    return 0;
}
