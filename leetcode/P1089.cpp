#include <bits/stdc++.h>
using namespace std;
int main(){
        int c,s = 0,h = 0;                
        for(int i = 1;i <= 12; i++)          
        {
                scanf("%d", &c);
                s += 300;                 
                s -= c;                        
                if(s < 0)                          
                {
                        printf("-%d", i);             
                        return 0;                       
                }
                else h += s / 100,s %= 100;     
        }
        printf("%d", 120*h+s);            
        return 0;
}