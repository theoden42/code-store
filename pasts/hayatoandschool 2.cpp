#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

void solve() {
	int n;
	cin >> n;
	vector<int> ele(n);
	int odd = 0, even = 0;
	for(int i = 0; i < n; i++){
		cin >> ele[i];
		if(ele[i] & 1)odd++;f
		else even++;
	}
	if(odd >= 3){
		vector<int> temp;
		cout << "YES\n";
		for(int i = 0; i < n && temp.size() < 3; i++){
			if(ele[i] & 1)temp.push_back(i + 1);
		} 
		for(auto& x: temp){
			cout << x << " ";
		}	
		cout << "\n";
	}
	else if(odd >= 1 && even >= 2){
		vector<int> temp;
		cout << "YES\n";
		for(int i = 0; i < n; i++){
			if(ele[i] & 1){
				temp.push_back(i + 1);
				break;
			}
		}
		for(int i = 0; i < n && temp.size() < 3; i++){
			if(ele[i] & 1){
				continue;
			}
			temp.push_back(i + 1);
		}
		for(auto& x: temp){
			cout << x << " ";
		}
		cout << "\n";
	}
	else{
		cout << "NO\n";
	}

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int testcases = 1;
    cin >> tc;
    for (int t = 1; t <= testcases; t++) {
        solve();
    }
}