#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}

	stack<pair<int,int>> st;
	vector<int> res(n);
	for(int i = n - 1; i >= 0; i--){
		while(!st.empty() && st.top().first <= a[i]){
			st.pop();
		}
		if(st.empty()){
			res[i] = 0;
		} else {
			res[i] = st.top().second - i;
		}
		st.push({a[i], i});
	}
	for(int i = 0; i < n; i++){
		cout << res[i] << " ";
	}
	cout << "\n";
}