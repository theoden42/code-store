
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
#define int long long
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e6 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

void solve() {
    int n;
    cin >> n;
    vector<int> ele(n);
    for(int i = 0; i < n; i++){
    	cin >> ele[i];
    }
    sort(all(ele));

    vector<int> val(n);
    for(int i = 0; i < n; i++){
    	val[i] = 2 * ele[i];
    }


    auto closest = [&](int l, int r, int target){

		int lower = l + 1;
		int upper = r - 1;
        // debug(lower, upper, val[lower], val[upper]);
        int mn = 1e18;
        while(lower <= upper){
            int mid = (lower + upper) / 2;
            int v = abs(val[mid] - target);
            if(v < mn){
                mn = v;
                if(val[mid] < target){
                    lower = mid + 1;
                }
                else{
                    upper = mid - 1;
                }
            }
            else{
                if(val[mid] < target){
                    lower = mid + 1;
                }
                else{
                    upper = mid - 1;
                }
            }
        }
        return mn;
    };

    ll gmin = 1e18;

    for(int i = 0; i < n; i++){
    	for(int j = i + 2; j < n; j++){
    		ll sum = ele[i] + ele[j];
            ll c = closest(i, j, sum);
            gmin = min(gmin, c);
    	}
    }
    cout << gmin << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}