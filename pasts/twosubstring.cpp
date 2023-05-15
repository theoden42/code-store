
/* @uthor: (g)theoden42 */

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

void solve() {
	string s;
	cin >> s;
	vector<int> ab;
	vector<int> ba;
	int n = s.length();
	for(int i = 0; i < n; i++){
		if(s[i] == 'A'){
			if(i < n - 1){
				if(s[i + 1] == 'B'){
					ab.push_back(i);
				}
			}
		}
		else if(s[i] == 'B'){
			if(i < n - 1){
				if(s[i + 1] == 'A'){
					ba.push_back(i);
				}
			}
		}
	}
	// cout << ab.size() << "\n";
	// cout << ba.size() << "\n";
	// for(auto& x : ba){
	// 	cout << x << " ";
	// }
	// for(auto& x : ab){
	// 	cout << x << " ";
	// }
	// cout << "\n";
	if(ab.size() == 0 || ba.size() == 0){
		cout << "NO" << "\n";
	}
	else if(ab.size() >= 2 && ba.size() >= 2){
		cout << "YES" << "\n";
	}
	else if(ab.size() >= 2){
		if(ab.size() > 2){
			cout << "YES" << "\n";
			return;
		}
		if((ab[0] == ba[0] + 1 || ab[0] == ba[0] - 1) && (ab[1] == ba[0] + 1 || ab[1] == ba[0] - 1)){
			cout << "NO" << "\n";
		}
		else{
			cout << "YES" << "\n";
		}	
	}
	else if(ba.size() >= 2){
		if(ba.size() > 2){
			cout << "YES" << "\n";
			return;
		}
		if((ab[0] == ba[0] + 1 || ab[0] == ba[0] - 1) && (ab[0] == ba[1] + 1 || ab[0] == ba[1] - 1)){
			cout << "NO" << "\n";
		}
		else{
			cout << "YES" << "\n";
		}
	}
	else{
		if(ab[0] == ba[0] + 1 || ab[0] == ba[0] - 1){
			cout << "NO" << "\n";
		}
		else{
			cout << "YES" << "\n";
		}
	}
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    //cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}