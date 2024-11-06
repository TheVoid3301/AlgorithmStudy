#include <bits/stdc++.h>
using namespace std;
int main(){
    char s[85];
    int k = 0, sum = 0;
    scanf("%s", s);
    for(int i = 0; i < strlen(s); ++i){
        if(s[i] == 'O'){
            ++k;
            sum += k;
        }else{
            k = 0;
        }
    }
    printf("%d\n", sum);
    return 0;
}