
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
    int n;
    cin >> n;
    vector<int> ele(n, 0);
    for(int i = 0; i < n; i++){
    	cin >> ele[i];
    }
    map<int,int> mp;
    sort(ele.begin(), ele.end());
	int ca = 0;
	int cb = 0;

	for(int i = 0; i < n; i++){
		mp[ele[i]] = 1;
		if(ele[i] < 0){
			ca++;
		}
		else if(ele[i] > 0){
			cb++;
		}
	}
	if(ca > 2 || cb > 2){
		cout << "NO" << "\n";
		return;
	}
	int m = ca + cb;
	if(mp[0] == 1){
		m++;
	}
	vector<int> vals(m, 0);
	int m1 = 0;
	for(int i = 0; i < n; i++){
		if(ele[i] != 0){
			vals[m1] = ele[i];
			m1++;
		}
	}
	if(mp[0] == 1){
		vals[m1] = 0;
	}
	// for(auto& x : vals){
	// 	cout << x << " ";
	// }
	// cout << "\n";
	for(int i = 0; i < m; i++){
		for(int j = i + 1; j < m; j++){
			for(int k = j + 1; k < m; k++){
				// cout << vals[i] << " " << vals[j] << " " << vals[k] << "\n";
				// cout << vals[i] + vals[j] + vals[k] << "\n";
				if(mp.find(vals[i] + vals[j] + vals[k]) == mp.end() || mp[vals[i] + vals[j] + vals[k]] == 0){
					cout << "NO" << "\n";
					return;
 				}
			}
		}
	}
	cout << "YES" << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}