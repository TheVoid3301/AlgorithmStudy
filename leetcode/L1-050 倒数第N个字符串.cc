#include <bits/stdc++.h>
using namespace std;

int main()
{
    int L,N;
    cin >> L >> N;
    stack<int> s;   //利用栈的“先进先出”
    int num = pow(26,L)-N;
    while(num)
    {
        s.push(num%26);  
        num /= 26;
    }
    for(int i = 0; i < L-s.size(); i++)   //补a
    {
        cout << "a";
    }
    while(!s.empty())   //清仓大甩卖
    {
        cout << (char)('a' + s.top());
        s.pop();
    }
    return 0;
}