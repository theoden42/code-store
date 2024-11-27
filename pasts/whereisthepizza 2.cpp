
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


void dfs(int ind, vector<int>& a, vector<int>& b, vector<int>& inda, vector<int>& vis){
	// we are on indi and therefore we have to take this ind;
	if(vis[ind])return;

	vis[ind] = 1;
	int val = inda[b[ind]]; // nextvalue to visit;
	dfs(val, a, b, inda, vis);
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    vector<int> d(n);

    vector<int> inda(n + 1);
    vector<int> indb(n + 1);

	for(int i = 0; i < n; i++){
		cin >> a[i];
		inda[a[i]] = i;
	}
	for(int i = 0; i < n; i++){
		cin >> b[i];
		indb[b[i]] = i;
	}
	for(int i = 0; i < n; i++){
		cin >> d[i];
	}

	ll count = 1;
	vector<int> vis(n);

	for(int i = 0; i < n; i++){
		if(a[i] == b[i]){
			vis[i] = 1;
			continue;
		}
	}

	for(int i = 0; i < n; i++){
		if(vis[i])continue;
		if(d[i] == a[i]){
			dfs(i, a, b, inda, vis);
		}
	}

	for(int i = 0; i < n; i++){
		if(vis[i])continue;
		if(d[i] == b[i]){
			dfs(i, b, a, indb, vis);
		}
	}
	vector<int> tempvis = vis;

	for(int i = 0; i < n; i++){
		if(vis[i] || tempvis[i])continue;
		count = (count * 2) % MOD;
		dfs(i, a, b, inda, tempvis);
		dfs(i, b, a, indb, vis);
	}
	cout << count << "\n";

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