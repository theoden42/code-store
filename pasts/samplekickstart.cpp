#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n, m; 
	cin >> n >> m;
	int temp = 0;
	int sum = 0;
	for(int i = 0; i<n; i++){
		cin >> temp;
		sum += temp;
	}
	cout << (sum) % m << "\n";
}

int main(){
	int t = 1;
	cin >> t;
	int i = 1;
	while(t-- > 0){
		cout << "Case #" << i << ": ";
		solve(); 
		i++;
	}
}