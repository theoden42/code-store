
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
	    vector<ll> prefix(n, 0);
	    for(int i = 0; i < n; i++){
	    	if(i == 0){
	    		prefix[i] = ele[i];
	    	}
	    	else{
	    		prefix[i] = prefix[i - 1] + ele[i];
	    	}
	    }
	    ll sum = 0;
	    for(int i = 0; i < n; i++){
	    	ll s = prefix[i];
	    	int l = i + 1;
	    	int u = n - 1;
	    	int flag = 0;
	    	while(l <= u){
	    		int mid = l + (u - l)/2;
	    		if(prefix[n - 1] - prefix[mid - 1] == s){
	    			flag = 1;
	    			break;
	    		}
	    		else if(prefix[n - 1] - prefix[mid - 1] < s){
	    			u = mid - 1;
	    		}
	    		else{
	    			l = mid + 1;
	    		}
	    	}
	    	if(flag == 1){
	    		sum = s;
	    	}
	    }
	    cout << sum << "\n";
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