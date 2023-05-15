#include <bits/stdc++.h>
using namespace std;

int main(){

	int n;
	cin >> n;
	vector<int> ar(n);

	for(int i = 0; i<n; i++){
		cin >> ar[i];
	}
	for(int i = 1; i<n; i++){
		for(int j = 0; j<n-1; j++){
			if(ar[j] > ar[j+ 1]){
				int temp = ar[j];
				ar[j] =  ar[j + 1];
				ar[j+1] = temp;
			}
		}
		for(int j = 0; j<n; j++){
			cout << ar[j] << " ";
		}
		cout << "\n";
	}

	return 0;
}