
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
    vector<ll> ele(n);
    for(int i = 0; i < n; i++){
    	cin >> ele[i];
    }
    ll sum = 0;

    map<ll,ll> mp;

    for(int i = 0; i < n; i++){
    	sum += ele[i];
    	mp[ele[i]] += 1;
    }

    vector<int> ans;

    for(int i = 0; i < n; i++){
    	ll sum2 = sum - ele[i];
    	mp[ele[i]] -= 1;

    	debug(sum2, mp);
    	if(sum2 % 2 == 0){
    		if(mp.find(sum2 / 2) != mp.end() && mp[sum2 / 2] != 0){
    			ans.push_back(i + 1);
    		}
    	}
    	mp[ele[i]] += 1;
    }


    cout << ans.size() << "\n";
    for(auto& x: ans){
    	cout << x << " ";
    }
    cout << "\n";
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