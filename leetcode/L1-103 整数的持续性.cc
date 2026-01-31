#include<iostream>
#include<vector>
using namespace std;
 
void solve(){
	int a, b;
    cin >> a >> b;
 
    int mp = 0;
    vector<int> nums;
 
    for (int n = a; n <= b; ++n) {
        int cp = 0;
        int num = n;
 
        while (num >= 10) {
            int prod = 1;
            while (num > 0) {
                prod *= num % 10;
                num /= 10;
            }
            num = prod;
            cp++;
        }
 
        if (cp > mp) {
            mp = cp;
            nums.clear();
            nums.push_back(n);
        } else if (cp == mp) {
            nums.push_back(n);
        }
    }
 
    cout << mp << endl;
    for (int i = 0; i < nums.size(); ++i) {
        if (i > 0) cout << " ";
        cout << nums[i];
    }
    cout << endl;
    
}
 
int main(){
	int t = 1;
	// cin >> t;
	while(t --)
	solve();
	return 0;
}
 