
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

pair<int,int> dfs(int source, int parent, vector<vector<int>>& g, vector<int>& a, vector<pair<int,int>>& vals){
	int countone = 0;
	int countzero = 0;
	a[source] == 1 ? countone++: countzero++;

	for(auto& x: g[source]){
		if(x != parent){
			auto p = dfs(x, source, g, a, vals);
			countone += p.first;
			countzero += p.second;
		}
	}

	vals[source] = {countone, countzero};
	return vals[source];
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
    	cin >> a[i];
    }
    vector<vector<int>> g(n);
    for(int i = 0; i < n - 1; i++){
    	int a, b;
    	cin >> a >> b;
    	a--;
    	b--;
    	g[a].push_back(b);
    	g[b].push_back(a);
    }

    vector<pair<int,int>> vals(n, {0, 0});
    vals[0] = dfs(0, -1, g, a, vals);

    debug(vals);


    int total1 = vals[0].first;
    int total0 = vals[0].second;

    int mx = 0;

    for(int i = 0; i < n; i++){
    	int x = vals[i].first;
    	int y = vals[i].second;
    	int xb = total1 - vals[i].first + 1;
    	int yb = total0 - vals[i].second + 1;
    	mx = max({x - y, xb - yb});
        cout << mx << " ";
    }


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