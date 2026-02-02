#include<bits/stdc++.h>
using namespace std;
 
// 常量定义：最大参与人数（题目中N≤10^4）
const int N = 1e4 + 5;
 
// 用户信息结构体
struct node{
    int num1 = 0;  // 净收入（以分为单位，正数表示收入，负数表示支出）
    int num2 = 0;  // 抢到的红包个数
    int id;        // 用户编号
} arr[N];  // 用户信息数组，下标对应用户编号
 
// 用户排序比较函数
// 排序规则：1. 按净收入降序；2. 若收入相同，按抢到的红包个数降序；3. 若前两者相同，按用户编号升序
bool cmp(node a, node b){
    if(a.num1 == b.num1){
        if(a.num2 == b.num2) return a.id < b.id;
        return a.num2 > b.num2;
    }
    return a.num1 > b.num1;
}
 
// 核心解决函数
void solve(){
    int n;  // 参与总人数
    cin >> n;
    
    // 遍历每个人的发红包记录
    for(int i = 1; i <= n; ++i){
        int k;  // 发出的红包个数
        cin >> k;
        arr[i].id = i;  // 设置用户编号
        
        // 处理每个发出的红包
        for(int j = 1; j <= k; ++j){
            int nx;  // 抢到红包的用户编号
            int p;   // 红包金额（以分为单位）
            cin >> nx >> p;
            
            // 更新抢红包用户的收入和红包个数
            arr[nx].num1 += p;
            arr[nx].num2++;
            
            // 更新发红包用户的支出（收入减少）
            arr[i].num1 -= p;
        }
    }
    
    // 按照比较规则对所有用户进行排序
    sort(arr + 1, arr + 1 + n, cmp);
    
    // 输出排序后的结果
    for(int i = 1; i <= n; ++i){
        // 输出用户编号，以及净收入（转换为元，保留两位小数）
        cout << arr[i].id << ' ' << fixed << setprecision(2) << (double)arr[i].num1 / 100 << endl;
    }
}
 
int main(){
    solve();  // 调用解决函数
    return 0;
}