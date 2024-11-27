 #include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	int ar[n];
	for(int i = 0; i<n; i++){
		cin >> ar[i];
	}
	int min = ar[0];
	int minindex = 0;

	for(int i = 0; i<n; i++){
		if(min > ar[i]){
			min = ar[i];
			minindex = i;
		}
	}
	cout << minindex << " ";
}