#include<stdio.h>
const int h=1e5;
int main(){
    int n;
    scanf("%d",&n);
    int mp[h+1]={0};//初始化宝石闪亮度统计表
    for(int i=0;i<n;i++){
        int t;
        scanf("%d",&t);
        mp[t]++;//统计亮度为t的宝石数量
    }
    //这里我们另辟蹊径，直接枚举精美程度
    for(int i=h;i>=1;i--){//枚举精美程度i
        int ans=0,now=0;//ans表示寻找到了几个宝石，now表示现在数组有几个宝石
        int num[3];//初始化枚举到的宝石
        for(int j=i;j<=h;j+=i){//对于每个精美度i，我们都需要寻找闪亮度为i，2i，3i...的宝石并统计数量
            ans+=mp[j];//把寻找到的宝石数量统计起来
            for(int k=0;k<mp[j]&&now<3;k++){//把统计到的宝石放到数组
                num[now]=j;
                now++;
            }
            if(ans>=3){//如果找到了三个以上的宝石，说明存在三个宝石使其精美度为i
                for(int k=0;k<3;k++){
                    printf("%d ",num[k]);
                }//输出找到的三个宝石
                printf("\n");
                return 0;
            }
        }
    }
}