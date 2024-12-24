#include<iostream>
#include<cmath>
using namespace std;
typedef long long ll;
const int N=1e4;
const ll X=343720;
const ll Y=233333;
int main(){
    for(ll x=2;x<=N;x+=2){
        for(ll y=2;y<=N;y+=2){
            if (15*Y*y==17*X*x){
                cout << x << "  " << y;
                return 0;
            }
        }
    }
}