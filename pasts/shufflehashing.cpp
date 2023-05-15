#include <bits/stdc++.h>
using namespace std;

void solve(){
	string p, h;
	cin >> p >> h;

	if(p.size() > h.size()){
		cout << "NO\n";
		return;
	}
	sort(p.begin(), p.end());
	int flag = 0;
	for(int i = 0; i<= h.size() - p.size(); i++){
		string sub = h.substr(i, p.size());
		sort(sub.begin(), sub.end());
		int b = 1;
		for(int j = 0; j<p.size(); j++){
			if(sub[j] != p[j]){
				b=0;
				break;
			}
		}
		if(b == 1){
			flag = 1;
			break;
		}
	}
	if(flag == 1){
		cout << "YES" << "\n";
	}
	else{
		cout << "NO" << "\n";
	}
}

int main(){
	int t = 1;
	cin >> t;
	while(t-- > 0){
		solve();
	}
}