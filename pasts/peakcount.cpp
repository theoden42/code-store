#include <bits/stdc++.h>
using namespace std

int main(){
	int n;
	cin >> n;
	vector<int> ar(n);
	for(int i = 0; i<n; i++){
		cin >> ar[i];
	}
	vector<int> peaks;
	vector<int> div;

	for(int i = 1; i<n-1; i++){
		if(ar[i]>ar[i-1] && ar[i]> ar[i+1]){
			peaks.push_back(i);
		}
	}
	for(int i = 1; i*i<=n; i++){
		if(i != n/i){
			div.push_back(i);
			div.push_back(n/i);
		}
		else{
			div.push_back(i);
		}
	}
	sort(div.begin(), div.end());
	for(int i : div){
		int pos = 0;
		int l = 0;
		int rr = i - 1;
		while(rr<n){
			while(ll < peaks[pos] && peaks[pos] < rr){
				count ++;
				pos ++ ;
			}
			ll += i;
			rr += i;
		}
	}
	return 0;
}