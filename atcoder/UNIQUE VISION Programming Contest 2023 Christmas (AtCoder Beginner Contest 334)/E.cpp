

/* author: (g)theoden42 */

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define all(a) a.begin(), a.end()
#ifdef ON_PC
    #include <debug.h>
#else
    #define debug(x...)
#endif

template<typename T>
using ordset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
using ll =  long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MAX_N = 1e6 + 5;
const ll MOD = 998244353;
const ll INF = 1e9;

#define int long long

ll binpow(ll a, ll b)
{
    ll ans = 1;
    while(b){
        if(b & 1){
        	ans = (ans * a) % MOD;
        }
        a = (a * a) % MOD;
        b = b >> 1; 
    }
    return (ans % MOD);
}

ll modinverse(ll a, ll b){
	return binpow(a, b - 2) % MOD;
}

vector<pair<int,int>> d = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void solve() {
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    for(int i = 0; i < h; i++){
    	cin >> s[i];
    }

   	vector<vector<int>> vis(h, vector<int>(w, 0));
   	vector<vector<int>> pnt(h, vector<int>(w, 0));
   	int p = 1;
   	int count = 0;

   	function<void(int,int,int)> dfs 
   	= [&](int i, int j, int p){
   		if(i < 0 || i >= h || j < 0 || j >= w || vis[i][j] || s[i][j] != '#')
   			return;
   		vis[i][j] = 1;
   		pnt[i][j] = p;
   		for(auto [dx, dy] : d){
   			int nx = i + dx;
   			int ny = j + dy;
   			dfs(nx, ny, p);
   		}
   	};



   	for(int i = 0; i < h; i++){
   		for(int j = 0; j < w; j++){
   			if(s[i][j] == '#' && !vis[i][j]){
   				dfs(i, j, p);
   				p += 1;
   			} else if(s[i][j] == '.'){
                count += 1;
   			}
   		}
   	}

   	int comp = p - 1;
   	int ans = 0;
   	for(int i = 0; i < h; i++){
   		for(int j = 0; j < w; j++){
            if(s[i][j] != '.')
                continue;
   			set<int> st;
   			for(auto [dx, dy]: d){
   				int nx = i + dx;
   				int ny = j + dy;
   				if(nx < 0 || nx >= h || ny < 0 || ny >= w)
   					continue;
   				if(s[nx][ny] == '#'){
                    // debug(pnt[nx][ny]);
   					st.insert(pnt[nx][ny]);
   				}
   			}
   			int ncomp = comp - (ll)st.size() + 1;
   			ans += ncomp;
   			ans %= MOD;
   		}
   	}

   	ans *= modinverse(count, MOD);
   	ans %= MOD;

   	cout << ans << "\n";

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