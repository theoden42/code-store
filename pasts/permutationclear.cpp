
/* @uthor: (g)theoden42 */

#include <bits/stdc++.h>
using namespace std;

#ifdef ON_PC
    #include <debug.h>
#else
    #define debug(x...)
#endif

#define ll long long
#define ld long double
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e6 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

void solve() {
    int n;
    cin >> n;
    vector<int> ele(n, 0);
    for(int i = 0; i < n; i++){
    	cin >> ele[i];
    }
    map<int,int> mp;
	int k;
	cin >> k;
	vector<int> b(k, 0);
	for(int i = 0; i < k; i++){
		int x;
		cin >> x;
		mp[x] = 1;
	}
	vector<int> ans;
	for(int i = 0; i < n; i++){
		if(mp.find(ele[i]) == mp.end()){
			ans.push_back(ele[i]);
		}
	}
	for(auto& x: ans){
		cout << x << " ";
	}
	cout << "\n";
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