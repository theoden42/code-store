
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
    ll temp = n;
    vector<pair<int,int>> fax;

    for(int i = 2; i * i <= temp; i++){
    	if(temp % i == 0){
    		int pow = 0;
    		while(temp % i == 0){
    			pow += 1;
    			temp /= i;
    		}
    		fax.push_back({pow, i});
    	}
    }
    if(temp != 1){
    	fax.push_back({1, temp});
    }



    ll prod = 1;
    for(int i = 0; i < fax.size(); i++){
    	prod *= fax[i].second;
    }
    sort(all(fax));
    debug(fax);


    ll ans = 0;
    ll done = 0;
    for(int i = 0; i < fax.size(); i++){
    	debug(prod, fax[i].first);
    	ans += prod * (fax[i].first - done);
    	prod /= fax[i].second;
    	done = fax[i].first;
    	debug(ans);
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