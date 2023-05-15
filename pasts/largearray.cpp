#include <bits/stdc++.h>
using namespace std;
 
int main(){
	int n; 
	cin >> n;
	vector<int> element(n);
	map<int, int> mp;
	map<int, int> size;
	for(int i = 0; i<n; i++){
		cin >> element[i];
	}
	int max = 0;
	int ele = 0;
	for(int i = 0; i < n; i++){
		if(mp.find(element[i]) == mp.end()){
			mp[element[i]] = 1;
		}
		else{
			mp[element[i]]++;
		}
	}
	for(auto& it : mp){
		if(it.second >= max){
			max = it.second;
			ele = it.first;
		}
	}
	int ind1 = 0; int ind2 = 0;
	for(int i = 0; i < n; i++){
		if(element[i] == ele){
			ind1 = i;
			break;
		}
	}
	for(int i = n - 1; i >= 0; i--){
		if(element[i] == ele){
			ind2 = i;
			break;
		}
	}
	cout << ind1 + 1 << " " << ind2 + 1<< "\n";
}