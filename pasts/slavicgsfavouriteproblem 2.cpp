
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


void findpathxor(int source, int b, vector<vector<pair<int,int>>>& g, vector<int>& vis, vector<int>& gxor){

	vis[source] = 1;
	if(source == b)return;

	for(auto& x: g[source]){
		if(vis[x.first])continue;
		gxor[x.first] = (gxor[source] ^ x.second);
		findpathxor(x.first, b, g, vis, gxor);
	}
}

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    vector<vector<pair<int,int>>> g(n);
    for(int i = 0; i < n - 1; i++){
    	int x, y, w;
    	cin >> x >> y >> w;
    	x--;
    	y--;
    	g[x].push_back({y, w});
    	g[y].push_back({x, w});
   	}

   	vector<int> bxor(n, -1);
   	vector<int> axor(n, -1);
   	vector<int> vis(n, 0);

   	axor[a - 1] = 0;
   	findpathxor(a - 1, b - 1, g, vis, axor);

   	for(int i = 0; i < n; i++){
   		vis[i] = 0;
   	}	

   	bxor[b - 1] = 0;
   	findpathxor(b - 1, n + 1, g, vis, bxor);


   	debug(axor, bxor);


   	if(axor[b - 1] == 0){
   		cout << "YES\n";
   		return;
   	}
   	map<int,int> mp;
   	for(int i = 0; i < n; i++){
   		if(i != b - 1){
   			mp[bxor[i]] += 1;
   		}
   	}


   	debug(mp);

	for(int i = 0; i < n; i++){
		if(i != b - 1 && axor[i] != -1){
			if(mp.find(axor[i]) != mp.end()){
				cout << "YES\n";
				return;
			}
		}
	}
	cout << "NO\n";

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