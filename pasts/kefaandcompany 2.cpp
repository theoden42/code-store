
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
    int n, d;
    cin >> n >> d;
    vector<pair<int, int>> fr(n);
    for(int i = 0; i < n; i++){
    	int x, y;
    	cin >> x >> y;
    	fr[i] = {x, y};
    }
    sort(fr.begin(), fr.end());
    // for(int i = 0; i < n; i++){
    // 	cout << fr[i].first << ", " << fr[i].second << ": ";
    // }
    // cout << "\n";
    vector<ll> prefix(n, 0);
    prefix[0] = fr[0].second;
    for(int i = 1; i < n; i++){
    	prefix[i] = fr[i].second + prefix[i - 1];
    }
    ll m = 0;
    for(int i = 0; i < n; i++){
    	int find = fr[i].first + d;
    	int l = i + 1;
    	int u = n - 1;
    	int index = -1;
    	while(l <= u){
    		int mid = l + (u - l) / 2;
    		if(fr[mid].first < find){
    			l = mid + 1;
    			index = mid;
    		}
    		else{
    			u = mid - 1;
    		}
    	}
    	ll ans = 0;
    	if(index == -1){
    		ans = fr[i].second;
    	}
    	else{
    		ans = prefix[index] - prefix[i] + fr[i].second;
    	}
    	m = max(m, ans);
    }
    cout << m << "\n";
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