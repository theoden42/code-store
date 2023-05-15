
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
int ans = 0;

void dfs(int source, int parent, vector<vector<int>>& g, vector<int>& vis){
	if(vis[source])return;
	if(parent == -1) ans *= 3;
	else ans *= 2;
	int count = 0;
	for(auto& x: g[source]){
		if(vis[x])count++;
	}
}


void solve() {	

// 3 unique ways for triangle 
	// 3 * 2 * ()
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