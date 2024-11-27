
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

bool check(vector<int>& ele, ll sum, ll moves, ll k){
	int n = ele.size();

	ll suffix = 0;
	for(int i = 0; i <= n - 1 && i <= moves; i++){
		// i chose to decrease the value of i elements/
		// what values can i reduce the sum to ?
		ll s = 0;
		ll val = moves - i;
		s += val; // decrease the first element first of all. 
		i == 0 ? : suffix += ele[n - i];
	 	// decrease in sum again = initial value - final values;

	 	ll new_val = ele[0] - val;

	 	s += (suffix - i * new_val);
	 	if(sum - s <= k)return 1;

	}
	return 0;

}

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<int> ele(n, k);
    for(int i = 0; i < n; i++){
    	cin >> ele[i];
    }

    ll sum = 0;
    sum = accumulate(all(ele), 0ll);
    sort(all(ele));
    debug(ele, sum);

    ll l = 0;
    ll u = 1e18;
    ll ans = 1e18;
    while(l <= u){
    	ll mid = l + (u - l) / 2;
    	if(check(ele, sum, mid, k)){
    		ans = mid;
    		u = mid - 1;
    	}
    	else{
    		l = mid + 1;
    	}
    }
    cout << ans << "\n";

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