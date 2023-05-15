
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
	int n = s.size();
	vector<int> eight;
	for(int i = 0; i <= 999; i++){
		if(i % 8 == 0){
			eight.push_back(i);
		}
	}
	for(auto& x: eight){
		string l = to_string(x);
		int k = l.size() - 1;
		for(int i = n - 1; i >= 0; i--){
			if(s[i] == l[k]){
				k--;
			}
			if(k == -1){
				break;
			}
		}
		if(k == -1){
			cout << "YES" << "\n";
			cout << l << "\n";
			return;
		}
	}
	cout << "NO" << "\n";

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