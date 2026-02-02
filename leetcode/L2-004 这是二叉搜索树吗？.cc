#include<bits/stdc++.h>
using namespace std;
bool isMirror;
vector<int>pre, post;
void getpost(int l, int r){//build(l,r)
    if(l > r)return ;
    int i = l+1, j = r;//l是根节点，pre[l+1,r]是左右子树
    if(!isMirror){
        while(i<=r && pre[l]>pre[i])i++; //从当前的根节点向后遍历
        while(j>l && pre[l]<=pre[j])j--; //从当前的尾节点向前遍历
    }else{
        while(i<=r && pre[l]<=pre[i])i++;
        while(j>l && pre[l]>pre[j])j--;
    }
    if(i-j!=1)return;//满足性质，存在一个分界点，左边都小于根，右边都大于根
    getpost(l+1,j);//存放左子树
    getpost(i,r);//存放右子树
    post.push_back(pre[l]);//存放根节点
}
int main(){
    int n;  cin>>n;
    pre.resize(n);
    for(int i = 0; i < n; i++)
        cin>>pre[i];
    getpost(0,n-1);
    if(post.size()!=n){
        isMirror = true;
        post.clear();
        getpost(0,n-1);
    }
    if(post.size()!=n){
        cout<<"NO"<<endl;
    }else{
        cout<<"YES"<<endl;
        for(int i = 0; i < n-1; i++)
            cout<<post[i]<<" ";
        cout<<post[n-1];
    }
    return 0;
}

