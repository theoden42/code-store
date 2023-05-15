
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


ll subsize(int l, int r){
	int len = (r - l + 1);

	if(len <= 0)return 0;

	ll ans = (1ll * len * (len + 1)) / 2;
	return ans;
}

ll sublength(int l, int r){
    if(l > r)return 0;
    else{
        return (0ll + r - l + 1);
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    map<int,int> mp, mp2;
    for(int i = 0; i < n; i++){
    	cin >> a[i];
    	mp[a[i]] = i;
    }
    for(int i = 0; i < n; i++){
    	cin >> b[i];
    	mp2[b[i]] = i;
    }

    int i = min(mp[1], mp2[1]);
    int j = max(mp[1], mp2[1]);
    ll count = 1;


    count += subsize(0, i - 1);
    count += subsize(j + 1, n - 1);
    count += subsize(i + 1, j - 1);

    for(int k = 2; k <= n; k++){
    	int x = min(mp[k], mp2[k]);
    	int y = max(mp[k], mp2[k]);

    	if((i <= x && x <= j) || (i <= y && y <= j)){
    		// atleast one is inside the segment, I have to take the whole segment
    		i = min(i, x);
    		j = max(j, y);
    	}
    	else{
    		// both are outside the segment, 
            int a, b;
    		if(x < i && y > j){
    			a = sublength(j, y - 1);
    		    b = sublength(x + 1, i);
    		}
    		else if(y < i){
    			a = sublength(y + 1, i);
                b = sublength(j, n - 1);
    		}
    		else if(x > j){
    			a = sublength(j, x - 1);
                b = sublength(0, i);
    		}
            else{
                assert(false);
            }

            count += 1ll * a * b;
            i = min(i, x);
            j = max(j, y);
    	}
    }

    cout << count << "\n";

}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    //cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}