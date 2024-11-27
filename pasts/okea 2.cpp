#include <bits/stdc++.h>
using namespace std;

int main(){

	int t =  1;
	cin >> t;
	while(t-- > 0){
		int n, k;
		cin >> n >> k;
		if(n == 1 && k == 1){
			cout << "YES" << "\n";
			cout << 1 << "\n";
		}
		else if( n % 2 != 0 && k > 1){
			cout << "NO" << "\n";
		}	
		else{
			cout << "YES"<<"\n";
			int codd = 1;
			int ceven = 2;
			for(int i = 1; i<=n; i++){
				for(int j = 1; j<=k; j++){
					if(i % 2 != 0){
						cout << codd << " ";
						codd += 2;
					}
					else{
						cout << ceven << " ";
						ceven += 2;
					}
				}
				cout << "\n";
			}
		}
	}

	return 0;
}