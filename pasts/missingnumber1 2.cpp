#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	
	int arr[n - 1];

	for(int i = 0; i < n - 1; i++){
		cin >> arr[i];
	}

	for(int i = 1; i <= n; i++){
		int flag = 0;
		for(int j = 0; j < n; j++){
			if(arr[j] == i){
				flag = 1;
			}
		}

		if(flag == 0){
			cout << i << "\n";
			return 0;
		}
	}
}