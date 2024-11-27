#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> perm(n + 1, 0);
	for(int i = 1; i <= n-1; i++){
		int x; 
		cin >> x;
		perm[x] = 1;
	}
	for(int i = 1; i<=n; i++){
		if(perm[i] == 0){
			cout << i << "\n";
			break;
		}
	}
}