
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


bool check(ll k, ll c, vector<ll>& ele, ll d){


	int n = ele.size();
	ll sum = 0;


	if(k >= d){
		for(int i = 0; i < d && i < n; i++){
			sum += ele[i];
		}
	}
	else{
		for(int i = 0; i <= k && i < n; i++){
			sum += 1ll * ele[i] * (d / (k + 1));
		}
		for(int i = 0; i < d % (k + 1) && i < n; i++){
			sum += ele[i];
		}
	}

	if(sum >= c)return 1;
	else return 0;
}

void solve() {
    ll n, c, d;
    cin >> n >> c >> d;
    vector<ll> ele(n);
    for(int i = 0; i < n; i++){
    	cin >> ele[i];
    }


    sort(ele.rbegin(), ele.rend());
    if(ele[0] * d < c){
    	cout << "Impossible" << "\n";
    	return;
    }

    ll sum = 0;
    for(int i = 0; i < d && i < n; i++){
    	sum += ele[i];
    }
    if(sum >= c){
    	cout << "Infinity\n";
    	return;
    }
    ll l = 0;
    ll u = d;
    ll mx = 0;
    while(l <= u){
    	ll mid = l + (u - l) / 2;
    	if(check(mid, c,  ele, d)){
    		mx = mid;
    		l = mid + 1;
    	}
    	else{
    		u = mid - 1;
    	}
    }
    cout << mx << "\n";
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