#include <bits/stdc++.h>
using namespace std;
int main(){
	string str;
	getline(cin,str);
	int maxlen = 0;
	for(int i = 0;i < str.length();i++){
		//假设最长对称子串长度为奇数，最小长度为1
		int temp = 1;
		for(int j = 1;j < str.length();j++){
			if(i - j < 0 || i + j >= str.length() || str[i+j] != str[i-j]){								
				break;	
			}				
			temp = j*2 + 1;
		}
		maxlen = max(maxlen,temp);
		//假设最长对称子串长度为偶数，最小长度为0
		temp = 0;
		for(int j = 1;j < str.length();j++){
			if(i - j + 1 < 0 || i + j >= str.length() || str[i+j] != str[i-j+1]){			
				break;	
			}
			temp = j*2;
		}
		maxlen = max(maxlen,temp);
	}
	cout<<maxlen<<endl;
	return 0;
}
