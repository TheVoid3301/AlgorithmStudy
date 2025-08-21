#include <bits/stdc++.h>
using namespace std;
int main(){
    char s[100];
    float sum = 0.0;
    scanf("%s", s);
    for(int i = 0; i < strlen(s) - 1; ++i){
        if(s[i] == 'C'){
            if(s[i + 1] >= '1' && s[i + 1] <= '9'){
                sum += 12.01 * (s[i + 1] - '0');
            }else{
                sum += 12.01;
            }
        }
        if(s[i] == 'H'){
            if(s[i + 1] >= '1' && s[i + 1] <= '9'){
                sum += 1.008 * (s[i + 1] - '0');
            }else{
                sum += 1.008;
            }
        }
        if(s[i] == 'O'){
            if(s[i + 1] >= '1' && s[i + 1] <= '9'){
                sum += 16.00 * (s[i + 1] - '0');
            }else{
                sum += 16.00;
            }
        }
        if(s[i] == 'N'){
            if(s[i + 1] >= '1' && s[i + 1] <= '9'){
                sum += 14.01 * (s[i + 1] - '0');
            }else{
                sum += 14.01;
            }
        }
    }
    if(s[strlen(s) - 1] == 'C'){
        sum += 12.01;
    }
    if(s[strlen(s) - 1] == 'H'){
        sum += 1.008;
    }
    if(s[strlen(s) - 1] == 'O'){
        sum += 16.00;
    }
    if(s[strlen(s) - 1] == 'N'){
        sum += 14.01;
    }
    printf("%.3f", sum);
    return 0;
}