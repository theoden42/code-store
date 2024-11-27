#include <bits/stdc++.h>
using namespace std;

int main(){

	int t = 1; 
	cin >> t;
	while(t-- > 0){
		int n, k;
		string str;
		cin >> n >> k;
		cin >> str;
		if(k == 0){
			cout << 1 << "\n";
		}
		else{
			int flag = 0;
			for(int i = 0; i<n/2; i++){
				if(str[i] ==  str[n - 1 - i]){
					continue;
				}
				else{
					flag = 1;
					break;
				}
			}
			if(flag == 1){
				cout << 2 << "\n";
			}
			else{
				cout << 1 << "\n";
			}
		}
}
}