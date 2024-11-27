
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
    int rs, rh;
    cin >> rs >> rh;
    int n;
    cin >> n;
    vector<pair<int,int>> red(n);
    for(int i = 0; i < n; i++){
    	int x, y;
    	cin >> x >> y;
    	red[i] = {x, y};
    }
    int m;
    cin >> m;

    vector<pair<int,int>> yellow(m);
    for(int i = 0; i < m; i++){
    	int x, y;
    	cin >> x >> y;
    	yellow[i] = {x, y};
    }
    for(int i = 0; i < n; i++){
    	ll d = 1ll * red[i].first * red[i].first + 1ll * red[i].second * red[i].second;
    	ll x = rs + rh;
    	x = x * x;
    	if(d > x){
    		red[i] = {-1e9, -1e9};
    	}
    }
    for(int i = 0; i < m; i++){
    	ll d = 1ll * yellow[i].first * yellow[i].first + 1ll * yellow[i].second * yellow[i].second;
    	ll x = rs + rh;
    	x = x * x;
    	if(d > x){
    		yellow[i] = {-1e9, -1e9};
    	}
    }
    ll mxa = 1e18;
    ll mxb = 1e18;

   	for(int i = 0; i < n; i++){
   		if(red[i].first == -1e9)continue;
   		ll x = red[i].first;
   		ll y = red[i].second;
   		ll d = x * x + y * y;
   		mxa = min(mxa, d);
   	}

   	for(int i = 0; i < m; i++){
   		if(yellow[i].first == -1e9)continue;
   		ll x = yellow[i].first;
   		ll y = yellow[i].second;
   		ll d = x * x + y * y;
   		mxb = min(mxb, d);
   	}

   	ll c1 = 0;
   	ll c2 = 0;

   	for(int i = 0; i < n; i++){
   		if(red[i].first == -1e9)continue;
   		ll x = red[i].first;
   		ll y = red[i].second;
   		ll d = x * x + y * y;
   		if(d <= mxb){
   			c1++;
   		}
   	}

   	for(int i = 0; i < m; i++){
   		if(yellow[i].first == -1e9)continue;
   		ll x = yellow[i].first;
   		ll y = yellow[i].second;
   		ll d = x * x + y * y;
   		if(d <= mxa){
   			c2++;
   		}
   	}

   	cout << c1 << " " << c2 << "\n";

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        cout << "Case #" << t << ": ";
        solve();
    }

}