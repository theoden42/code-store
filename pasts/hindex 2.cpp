#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<int> cit(n);
	vector<int> no(n + 1, 0);
	for(int i = 0; i<n; i++){
		cin >> cit[i];
	}
	for(int i = 0; i<n; i++){
		for(int j = 0; j <= cit[i] && j <= n; j++){
			no[j]++ ;
		}
		if(no[k + 1] >= k + 1){
			k += 1;
		}
		cout << k << " " ;
	}


}

int  main(){
	int t = 1;
	cin >> t;
	int i = 1;
	while(i <= t){
		cout << "Case #" << i << ": " ;
		solve();
		cout << '\n';
		i++;
	}
}